#include "ogl_renderer.h"
#include <SDL2/SDL_video.h>

namespace eightthreeegnine {
SDL_WindowFlags OpenGlRenderer::getWindowFlags() {
  SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL);
  return window_flags;
}
} // namespace eightthreeegnine