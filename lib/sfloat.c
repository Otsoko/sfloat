#include <stdint.h>
#include <math.h>

double sfloat2double(uint16_t raw) {
    int16_t mantissa = raw & 0x0FFF;
    if (mantissa >= 0x0800) mantissa -= 0x1000;

    int8_t exponent = (raw >> 12) & 0x0F;
    if (exponent >= 0x08) exponent -= 0x10;

    if (mantissa == 0x07FF) return NAN;
    if (mantissa == 0x0800) return NAN;
    if (mantissa == 0x07FE) return INFINITY;
    if (mantissa == 0x0802) return -INFINITY;

    double result = (double) mantissa;

    if (exponent > 0) {
        while (exponent--) result *= 10.0;
    } else {
        while (exponent++) result /= 10.0;
    }

    return result;
}


uint16_t double2sfloat(double value) {
    // Reserved values
    if (isnan(value))  return 0x07FF;                        // NaN
    if (isinf(value))  return (value > 0) ? 0x07FE : 0x0802; // +inf, -inf
    if (value == 0) return 0;

    // Mantissa range fot SFLOAT: [-2048, 2047]
    const int16_t MANTISSA_MAX = 2047;
    const int16_t MANTISSA_MIN = -2048;

    const double pow10[] = {
        1e-8, 1e-7, 1e-6, 1e-5, 1e-4, 1e-3, 1e-2, 1e-1,
        1, 10, 100, 1000, 10000, 100000, 1000000, 10000000
    };

    int best_exp = 0;
    int best_man = 0;
    double best_error = 1e300;

    // Loop exponents [-8 .. +7]
    for (int i = 0; i < 16; i++) {
        // Index to exponent
        int exp = i - 8;
        double scaled = value / pow10[i];

        int mant = (int) round(scaled);

        if (mant < MANTISSA_MIN || mant > MANTISSA_MAX)
            continue;

        double reconstructed = mant * pow10[i];
        double error = fabs(value - reconstructed);

        if (error < best_error) {
            best_error = error;
            best_exp = exp;
            best_man = mant;
        }
    }

    // Mantissa (12 bits signed)
    uint16_t mantissa = (best_man < 0)
        ? (0x1000 + best_man)
        : best_man;

    // Exponent (4 bits signed)
    uint16_t exponent = (best_exp < 0)
        ? (0x10 + best_exp)
        : best_exp;

    return (exponent << 12) | (mantissa & 0x0FFF);
}
