#pragma once

#include <LightComposer/i_light_hal.h>
#include <LightComposer/color/rgb_color.h>
#include "i_pixels.h"

class Pixels : public IPixels {
public:
	void setup(ILightHAL* hal);
	void set(RGBColor color);
	void set(RGBColor color, uint8_t idx);
	void set(RGBColor color, uint8_t from, uint8_t to);
	void mirror();
	RGBColor* raw();
	uint16_t count();
	uint16_t center();

private:
	ILightHAL* hal_;
	uint16_t count_ = 0;
	uint16_t center_ = 0;
};
