#pragma once
#include "../renderer/renderer.h"
#include "../renderer/opengl/ogl_renderer.h"

namespace eightthreeegnine {
class Engine {
  bool _isInitialized{false};
  int _frameNumber{0};
  bool running{false};

  float vertices[9] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f};

public:
  OpenGlRenderer renderer;

  void setRenderer(OpenGlRenderer given_renderer);

  void update();

  void run();

};
} // namespace eightthreeegnine