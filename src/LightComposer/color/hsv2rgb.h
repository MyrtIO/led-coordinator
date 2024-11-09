#pragma once

#include "rgb_color.h"
#include "hsv_color.h"

// Convert an HSV value to RGB using a visually balanced rainbow.
// This "rainbow" yields better yellow and orange than a straight
// mathematical "spectrum".
void hsv2rgb(const struct HSVColor& hsv, struct RGBColor& rgb);
