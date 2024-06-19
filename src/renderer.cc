#include "renderer.h"
#include <FastLED.h>

const uint8_t kDefaultFPS = 50;

LEDRenderer* LEDRenderer::start(IRenderer* brightness, IRenderer* pixels, uint8_t fps = kDefaultFPS) {
  setBrightnessHandler(brightness);
  setColorHandler(pixels);
  setFPS(fps);
  requestFrame_();
  return this;
}

LEDRenderer* LEDRenderer::setFPS(uint8_t fps) {
  frameTime_ = 1000 / fps;
  return this;
}

LEDRenderer* LEDRenderer::setBrightnessHandler(IRenderer* render) {
  brightness_ = render;
  return this;
}

LEDRenderer* LEDRenderer::setColorHandler(IRenderer* render) {
  color_ = render;
  return this;
}

void LEDRenderer::handle() {
  if (!shouldRenderFrame_()) {
    return;
  }
  bool hasChanges = false;
  hasChanges |= color_->handleFrame();
  hasChanges |= brightness_->handleFrame();
  if (hasChanges) {
    FastLED.show();
  }
  requestFrame_();
}

void LEDRenderer::requestFrame_() {
  frameDeadline_.start(frameTime_);
}

bool LEDRenderer::shouldRenderFrame_() {
  return frameDeadline_.finished();
}
