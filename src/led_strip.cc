#include "led_strip.h"

void LEDStrip::mirror() {
  for (uint8_t i = 0; i < (length_ / 2); i++) {
    leds_[length_ - i] = leds_[i];
  }
}

void LEDStrip::set(CRGB color, uint8_t idx) {
  leds_[idx] = color;
}

void LEDStrip::set(CRGB color, uint8_t from, uint8_t to) {
  for (uint8_t i = from; i < to; i++) {
    this->set(color, i);
  }
}

void LEDStrip::set(CRGB color) {
  this->set(color, 0, length_);
}

CRGB LEDStrip::get(uint8_t idx) {
  return leds_[idx];
}
