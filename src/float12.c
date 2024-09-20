#include "float12.h"


float float12_to_float32(uint16_t float12) {
    uint16_t sign = (float12 >> 11) & 0x1;          
    uint16_t exponent = (float12 >> 6) & 0x1F;     
    uint16_t fraction = float12 & 0x3F;           

    // Check for zero
    if (exponent == 0 && fraction == 0) {
        return 0.0f;
    }

    //Decode sign, exponent and fraction
    int sign_bit = sign ? -1 : 1;
    int exponent_value = exponent - 15; // Unbias the exponent
    float fraction_value = (float)fraction / (1 << 6); // Convert to a fraction in [0, 1)

    //TODO: Use bitwise operations instead
    return  sign_bit * (1.0f + fraction_value) * (1 << exponent_value);
}

