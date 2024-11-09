#pragma once

#include <stdint.h>
#include "scale.h"

// Ported from FastLED (https://github.com/FastLED/FastLED/blob/master/src/lib8tion)

// 8-bit fixed point fraction
typedef uint8_t fract_t;

static inline uint8_t blend8(uint8_t a, uint8_t b, fract_t amountOfB) {
    uint16_t partial;
    uint8_t result;

    partial = (a << 8) | b; // A*256 + B

    // on many platforms this compiles to a single multiply of (B-A) * amountOfB
    partial += (b * amountOfB);
    partial -= (a * amountOfB);

    result = partial >> 8;

    return result;
}

// Linear interpolation between two values, with the fraction between
// them expressed as an 8-bit fixed point fraction.
static inline uint8_t lerp8by8(uint8_t a, uint8_t b, fract_t frac) {
    uint8_t result;
    if( b > a) {
        uint8_t delta = b - a;
        uint8_t scaled = scale8( delta, frac);
        result = a + scaled;
    } else {
        uint8_t delta = a - b;
        uint8_t scaled = scale8( delta, frac);
        result = a - scaled;
    }
    return result;
}
