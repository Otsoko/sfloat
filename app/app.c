#include <stdio.h>
#include <sfloat.h>

int main() {
    uint16_t raw = 0xd5f0;
    double value = sfloat2double(raw);
    uint16_t sf = double2sfloat(value);
    double valueFromSf = sfloat2double(sf);
    printf("raw: 0x%04X, value: %8.2f, sf: 0x%04X, value sf: %8.2f\n", raw, value, sf, valueFromSf);

    raw = 0xf3e8;
    value = sfloat2double(raw);
    sf = double2sfloat(value);
    valueFromSf = sfloat2double(sf);
    printf("raw: 0x%04X, value: %8.2f, sf: 0x%04X, value sf: %8.2f\n", raw, value, sf, valueFromSf);

    raw = 0xf7d0;
    value = sfloat2double(raw);
    sf = double2sfloat(value);
    valueFromSf = sfloat2double(sf);
    printf("raw: 0x%04X, value: %8.2f, sf: 0x%04X, value sf: %8.2f\n", raw, value, sf, valueFromSf);

    raw = 0x1f4;
    value = sfloat2double(raw);
    sf = double2sfloat(value);
    valueFromSf = sfloat2double(sf);
    printf("raw: 0x%04X, value: %8.2f, sf: 0x%04X, value sf: %8.2f\n", raw, value, sf, valueFromSf);

    raw = 0xe113;
    value = sfloat2double(raw);
    sf = double2sfloat(value);
    valueFromSf = sfloat2double(sf);
    printf("raw: 0x%04X, value: %8.2f, sf: 0x%04X, value sf: %8.2f\n", raw, value, sf, valueFromSf);

    raw = 0xf3d4;
    value = sfloat2double(raw);
    sf = double2sfloat(value);
    valueFromSf = sfloat2double(sf);
    printf("raw: 0x%04X, value: %8.2f, sf: 0x%04X, value sf: %8.2f\n", raw, value, sf, valueFromSf);

    raw = 0xe0fc;
    value = sfloat2double(raw);
    sf = double2sfloat(value);
    valueFromSf = sfloat2double(sf);
    printf("raw: 0x%04X, value: %8.2f, sf: 0x%04X, value sf: %8.2f\n", raw, value, sf, valueFromSf);

    raw = 0x4d2;
    value = sfloat2double(raw);
    sf = double2sfloat(value);
    valueFromSf = sfloat2double(sf);
    printf("raw: 0x%04X, value: %8.2f, sf: 0x%04X, value sf: %8.2f\n", raw, value, sf, valueFromSf);

    raw = 0xb2e;
    value = sfloat2double(raw);
    sf = double2sfloat(value);
    valueFromSf = sfloat2double(sf);
    printf("raw: 0x%04X, value: %8.2f, sf: 0x%04X, value sf: %8.2f\n", raw, value, sf, valueFromSf);

    return 0;
}
