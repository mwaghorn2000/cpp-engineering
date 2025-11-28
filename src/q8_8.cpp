//
// Created by Mitch on 28/11/2025.
//

#include "../include/q8_8.h"

#include <complex>

#define SIGN_MASK (1 << 15)
#define INTEGER_MASK  (0x007F << 8)
#define FRACTION_MASK (0x00FF)

// Default constructor
q8_8::q8_8() {
    this->value = 0;
}

q8_8::q8_8(const int16_t v) {
    this->value = v;
}

float q8_8::toFloat() const {
    const int16_t& v = this -> value;
    const float integer = ((INTEGER_MASK & v) >> 8);
    const uint16_t fraction = ((FRACTION_MASK & v));
    const uint16_t sign = ((SIGN_MASK & v)) >> 15;

    uint16_t mask = 0x80;
    float fraction_sum = 0.0;
    for (int i = 8; i > 0; i--) {
        if (mask & fraction) {
            fraction_sum += static_cast<float_t> (mask) / 256.0f;
        }
        mask >>= 1;
    }

    float result = integer + fraction_sum;
    result = sign ? -result : result;
    return result;
}



