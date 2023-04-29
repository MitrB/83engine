#pragma once

#include "../renderer.h"
#include <SDL2/SDL_video.h>

namespace eightthreeegnine {
class OpenGlRenderer : public eightthreeegnine::Renderer {
public:
  float vertices[15] = {
      0.5f,  0.5f,  0.0f, // top right
      0.5f,  -0.5f, 0.0f, // bottom right
      -0.5f, -0.5f, 0.0f, // bottom left
      -0.5f, 0.5f,  0.0f, // top left
      -0.9f, 0.1f,  0.9f  // top left
  };
  int indices[9] = {0, 1, 3, 1, 2, 3, 4, 3, 1};

  SDL_WindowFlags getWindowFlags();
  void init();
  void draw();
  void cleanup();

private:
  unsigned int shaderProgram;
  unsigned int shaderProgram2;
  unsigned int VAO;
  unsigned int VBO;
  unsigned int EBO;
  SDL_GLContext maincontext;

  int initGlad();
};
} // namespace eightthreeegnine