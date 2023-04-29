#pragma once

#include "../renderer.h"
#include "../shader_manager.h"

namespace eightthreeegnine {
class OpenGlRenderer : public eightthreeegnine::Renderer {
public:
  float vertices[30] = {
      0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f, // top right
      0.5f,  -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // top right// bottom right
      -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, // top right// bottom left
      -0.5f, 0.5f,  0.0f, 1.0f, 1.0f, 0.0f, // top right// top left
      -0.9f, 0.1f,  0.9f,  1.0f, 0.0f, 1.0f // top right// top left
  };
  int indices[9] = {0, 1, 3, 1, 2, 3, 4, 3, 1};

  SDL_WindowFlags getWindowFlags();
  void init();
  void draw();
  void cleanup();

private:
  unsigned int VAO;
  unsigned int VBO;
  unsigned int EBO;
  SDL_GLContext maincontext;

  Shader simpleShader = Shader();

  int initGlad();
};
} // namespace eightthreeegnine