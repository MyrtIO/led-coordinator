#pragma once
#include "led_strip.h"

#include "state.h"

class IRenderer {
public:
  // Handle a frame of animation. Should return true if the frame should be rendered.
  virtual bool handleFrame() = 0;
};

class ILEDEffect : public IRenderer {
public:
  // Handle a frame of animation. Should return true if the frame should be rendered.
  virtual bool handleFrame(StripState* state, LEDStrip* strip) = 0;
  // Lifecycle hooks, called when the state target color changes
  virtual void onColorUpdate(StripState* state);
  // Lifecycle hooks, called when the effect changes.
  // Useful for static effects that need to render even when the color is not changing
  virtual void onEffectUpdate(StripState* state);
};
