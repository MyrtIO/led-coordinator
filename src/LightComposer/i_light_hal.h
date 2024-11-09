#pragma once

#include <stdint.h>
#include "color/rgb_color.h"

class ILightHAL {
public:
	virtual uint16_t count();
	virtual void setPixel(const uint16_t index, const RGBColor& color) = 0;
	virtual RGBColor getPixel(const uint16_t index) = 0;
	virtual void setBrightness(const uint8_t brightness) = 0;
	virtual void apply() = 0;
	virtual RGBColor* pixels();
};
