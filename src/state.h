#pragma once

#include <FastLED.h>

struct StripState {
  bool enabled;
  uint8_t currentBrightness;
  uint8_t targetBrightness;
  CRGB selectedColor;
  CRGB currentColor;
  CRGB targetColor;

  size_t colorTransitionMs  = 0;
  size_t effectTransitionMs = 0;
};
