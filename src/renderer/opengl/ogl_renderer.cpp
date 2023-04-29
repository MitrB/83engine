#include "../../../third_party/glad/include/glad/glad.h"
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>

#include "../shader_manager.h"
#include "ogl_renderer.h"

namespace eightthreeegnine {
  

SDL_WindowFlags OpenGlRenderer::getWindowFlags() {
  SDL_WindowFlags window_flags =
      (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
  return window_flags;
}

void OpenGlRenderer::draw() {


  glClearColor(0.8f, 0.9f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  simpleShader.use();
  glBindVertexArray(VAO);
  glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

  SDL_GL_SwapWindow(_window);
}

int OpenGlRenderer::initGlad() {

  // SDL_GL_GetProcAddress get's OS specific OpenGL function
  if (!gladLoadGLLoader(SDL_GL_GetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return 1;
  }
  return 0;
}

void OpenGlRenderer::init() {
  // Request an OpenGL 4.6 context (should be core)
  SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
  // Also request a depth buffer
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

  Renderer::init();
  maincontext = SDL_GL_CreateContext(_window);
  initGlad();

  // Remember in OpenGl the first 2 parameters are the LOWER-LEFT CORNER coords
  glViewport(0, 0, 640, 360); // setting the dimentions for the viewport

  simpleShader.init("../shaders/basic_shader.vert", "../shaders/basic_shader.frag");

  // creating buffer
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
               GL_STATIC_DRAW);

  // position attribute
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);
  // color attribute
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
                        (void *)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  // WireFrame mode
  // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void OpenGlRenderer::cleanup() {
  Renderer::cleanup();

  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteBuffers(1, &EBO);
}
} // namespace eightthreeegnine