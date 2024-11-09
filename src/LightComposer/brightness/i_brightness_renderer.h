#pragma once

#include <LightComposer/i_renderer.h>
#include <LightComposer/pixels/i_pixels_effect.h>

class IBrightnessRenderer: public IRenderer, public IEffectProvider {
public:
	virtual void attachComposer(IEffectChanger* composer, ILightHAL* hal) = 0;

	virtual void setBrightness(uint8_t brightness) = 0;
	virtual void setPower(bool enabled) = 0;
	virtual uint8_t getBrightness() = 0;
	virtual bool getPower() = 0;
};
