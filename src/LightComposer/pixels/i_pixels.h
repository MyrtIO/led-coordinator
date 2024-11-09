#pragma once

#include <LightComposer/color/rgb_color.h>
#include <LightComposer/i_light_hal.h>

class IPixels {
public:
	virtual void setup(ILightHAL* hal) = 0;
	virtual void set(RGBColor color) = 0;
	virtual void set(RGBColor color, uint8_t idx) = 0;
	virtual void set(RGBColor color, uint8_t from, uint8_t to) = 0;
	virtual void mirror() = 0;
	virtual RGBColor* raw();
	virtual uint16_t count();
	virtual uint16_t center();
};
