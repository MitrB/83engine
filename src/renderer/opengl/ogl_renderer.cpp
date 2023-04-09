#include "ogl_renderer.h"
#include "../../../third_party/glad/include/glad/glad.h"
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_video.h>

namespace eightthreeegnine {
SDL_WindowFlags OpenGlRenderer::getWindowFlags() {

  SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
  return window_flags;
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
}
} // namespace eightthreeegnine