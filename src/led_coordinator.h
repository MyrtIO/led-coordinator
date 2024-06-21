#pragma once

#include <Attotime.h>

#ifndef LED_MAX_HANDLERS
#define LED_MAX_HANDLERS 4
#endif

class IRenderer {
public:
  // Apply the current state to the LED strip
  virtual void apply() = 0;
};

class ILEDHandler {
public:
  // Handle a frame of animation. Should return true if the frame should be rendered.
  virtual bool handleFrame() = 0;
};

class LEDCoordinator {
public:
  // Constructor and initialization method
  void start(IRenderer *renderer, uint8_t fps);

  // Set the renderer
  void setRenderer(IRenderer *renderer) {
    renderer_ = renderer;
  }

  // Set the frame time
  void setFPS(uint8_t fps);

  template<typename... Args>
  void addHandlers(ILEDHandler *last) {
    addHandler_(last);
  }

  template<typename... Args>
  void addHandlers(ILEDHandler* first, Args... args) {
    addHandler_(first);
    return addHandlers(args...);
  }

  // Main handling method for updating LEDs
  void handle();

private:
  IRenderer* renderer_;
  ILEDHandler* handlers_[LED_MAX_HANDLERS];
  uint8_t handlersCount_ = 0;
  Timer frameDeadline_;
  uint8_t frameTime_;

  // Request the next frame
  void requestFrame_();

  // Check if it's time to render the frame
  bool shouldRenderFrame_();

  // Add a handler to the list
  void addHandler_(ILEDHandler* c);
};
