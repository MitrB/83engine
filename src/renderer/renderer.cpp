#include "renderer.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_video.h>

namespace eightthreeegnine {
void Renderer::init() {
  // We initialize SDL and create a window with it.
  SDL_Init(SDL_INIT_VIDEO);

  SDL_WindowFlags window_flags = getWindowFlags();

  _window =
      SDL_CreateWindow("83Engine", SDL_WINDOWPOS_UNDEFINED,
                       SDL_WINDOWPOS_UNDEFINED, width, height, window_flags);
}

void Renderer::cleanup() { SDL_DestroyWindow(_window); }

void Renderer::draw() {
  // nothing yet
}

void Renderer::run() {
  SDL_Event e;
  bool bQuit = false;

  // main loop
  while (!bQuit) {
    // Handle events on queue
    while (SDL_PollEvent(&e) != 0) {
      // close the window when user alt-f4s or clicks the X button
      switch (e.type) {
      case SDL_QUIT:
        bQuit = true;
      case SDL_WINDOWEVENT:
        if (e.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
          framebuffer_size_callback(_window, e.window.data1, e.window.data2);
        }
      }
    };
  }

  draw();
}

void Renderer::framebuffer_size_callback(SDL_Window *window, int width,
                                         int height) {
  glViewport(0, 0, width, height);
}

} // namespace eightthreeegnine