#include "led_coordinator.h"

const uint8_t kDefaultFPS = 50;

void LEDCoordinator::start(IRenderer *renderer, uint8_t fps = kDefaultFPS) {
  if (renderer == nullptr && renderer_ == nullptr) {
    printf("No LED renderer set!\n");
    return;
  } else if (renderer != nullptr) {
    setRenderer(renderer);
  }
  setRenderer(renderer);
  setFPS(fps);
  requestFrame_();
}

void LEDCoordinator::setFPS(uint8_t fps) {
  frameTime_ = 1000 / fps;
}

void LEDCoordinator::handle() {
  if (!shouldRenderFrame_()) {
    return;
  }
  bool hasChanges = false;
  for (uint8_t i = 0; i < handlersCount_; i++) {
    hasChanges |= handlers_[i]->handleFrame();
  }
  if (hasChanges) {
    renderer_->apply();
  }
  requestFrame_();
}

void LEDCoordinator::requestFrame_() {
  frameDeadline_.start(frameTime_);
}

bool LEDCoordinator::shouldRenderFrame_() {
  return frameDeadline_.finished();
}

void LEDCoordinator::addHandler_(ILEDHandler* c) {
    if (handlersCount_ >= LED_MAX_HANDLERS) {
      printf("Too many LED handlers!\n");
      return;
    }
    handlers_[handlersCount_] = c;
    handlersCount_++;
  }
