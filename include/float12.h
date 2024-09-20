#ifndef FLOAT12_H
#define FLOAT12_H

#include <stdint.h>

/*
 * Convert left-aligned 12-bit float to normal 32-bit float
 */
float float12_to_float32(uint16_t float12);

#endif


/* 
 * FLOAT12 
 * 
 * | S | EEEEE | FFFFFF | 0 | 0 | 0 | 0 | 0 | 0 |
 *
 * S: Sign bit (1 bit)
 * E: Exponent (5 bits)
 * F: Fraction (6 bits)
 *
 *
 *
 * FLOAT32
 *
 * | S | EEEEEEEE | MMMMMMMMMMMMMMMMMMMMMMM |
 *
 * S: Sign bit (1 bit)
 * E: Exponent (8 bits)
 * F: Fraction (23 bits)
 */

