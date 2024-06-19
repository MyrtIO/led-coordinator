#pragma once

#include "color_utils.h"
#include "interfaces.h"
#include <Attotime.h>

class LEDRenderer {
public:
  // Constructor and initialization method
  LEDRenderer* start(IRenderer* brightness, IRenderer* pixels, uint8_t fps);

  // Set the frame time
  LEDRenderer* setFPS(uint8_t fps);

  // Set the brightness renderer
  LEDRenderer* setBrightnessHandler(IRenderer* render);

  // Set the pixels renderer
  LEDRenderer* setColorHandler(IRenderer* render);

  // Main handling method for updating LEDs
  void handle();

private:
  IRenderer* brightness_ = nullptr;
  IRenderer* color_      = nullptr;
  Timer frameDeadline_;
  uint8_t frameTime_;

  // Request the next frame
  void requestFrame_();

  // Check if it's time to render the frame
  bool shouldRenderFrame_();
};
