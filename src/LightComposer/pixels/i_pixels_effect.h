#pragma once

#include <stdint.h>
#include <LightComposer/color/rgb_color.h>
#include <LightComposer/i_light_hal.h>
#include "i_pixels.h"

class IEffectProvider {
public:
	virtual void requestEffectChange();
};

class IEffectChanger {
public:
	virtual void onEffectChange();
};

template <class Locator = void>
struct LightState {
	RGBColor previousColor = 0;
	RGBColor currentColor = 0;
	RGBColor targetColor = 0;
	Locator* locator;
	uint16_t transitionMs = 0;
};

template <class Locator>
class IPixelsEffect {
public:
	// Handle a frame of animation.
	// Should return true if rendering is needed.
	virtual bool handleFrame(LightState<Locator>& state, IPixels& pixels) = 0;

	// Lifecycle hooks, called when the state target color changes
	virtual void onColorUpdate(LightState<Locator>& state) {}

	// Lifecycle hooks, called when the effect is activated
	virtual void onActivate(LightState<Locator>& state, IPixels& pixels) {}
};
