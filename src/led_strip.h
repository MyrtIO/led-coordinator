#pragma once

#include <FastLED.h>

class LEDStrip {
public:
  void mirror();
  void set(CRGB color);
  void set(CRGB color, uint8_t idx);
  void set(CRGB color, uint8_t from, uint8_t to);
  CRGB get(uint8_t idx);

protected:
  struct CRGB* leds_;
  uint8_t length_;
};

template <uint8_t DATA_PIN, uint8_t LENGTH>
class WS2812Strip : public LEDStrip {
public:
  explicit WS2812Strip(const struct CRGB& correction) {
    leds_   = new struct CRGB[LENGTH];
    length_ = LENGTH;
    FastLED.addLeds<WS2811, DATA_PIN, GRB>(leds_, length_).setCorrection(correction);
  }
};
