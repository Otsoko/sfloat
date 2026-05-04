#ifndef __SFLOAT_H__
#define __SFLOAT_H__

#include <stdint.h>

double sfloat2double(uint16_t raw);
uint16_t double2sfloat(double value);

#endif /* __SFLOAT_H__ */