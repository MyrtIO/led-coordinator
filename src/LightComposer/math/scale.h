#pragma once

#include <stdint.h>

// Ported from FastLED (https://github.com/FastLED/FastLED/blob/master/src/lib8tion)

// Scale an 8-bit value, where 0x00 represents 0% and 0xFF represents 100%
typedef uint8_t scale_t;

// Scale one byte by a second one, which is treated as the numerator of a fraction whose denominator is 256.
static inline uint8_t scale8(uint8_t x, scale_t scale) {
	return (((uint16_t)x) * (1 + (uint16_t)(scale))) >> 8;
}

// The "video" version of scale8() guarantees that the output
// will be only be zero if one or both of the inputs are zero.
static inline uint8_t scale8Video(uint8_t x, scale_t scale) {
	return (((int)x * (int)scale) >> 8) + ((x && scale) ? 1 : 0);
}
