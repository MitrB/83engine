#include <SDL2/SDL_keyboard.h>
#include <iostream>

#include "vk_engine.h"
#include "vk_inits.h"
#include "vk_types.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_vulkan.h>

void VulkanEngine::init() {
  // We initialize SDL and create a window with it.
  SDL_Init(SDL_INIT_VIDEO);

  SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_VULKAN);

  _window = SDL_CreateWindow("Vulkan Engine", SDL_WINDOWPOS_UNDEFINED,
                             SDL_WINDOWPOS_UNDEFINED, _windowExtent.width,
                             _windowExtent.height, window_flags);

  // everything went fine
  _isInitialized = true;
}
void VulkanEngine::cleanup() {
  if (_isInitialized) {

    SDL_DestroyWindow(_window);
  }
}

void VulkanEngine::draw() {
  // nothing yet
}

void VulkanEngine::run() {
  SDL_Event e;
  bool bQuit = false;

  // main loop
  while (!bQuit) {
    // Handle events on queue
    while (SDL_PollEvent(&e) != 0) {
      switch (e.type) {
      case SDL_QUIT: // quit event on alt+f4 or x-button
        bQuit = true;
      case SDL_KEYDOWN: // key down, print key name
        std::cout << SDL_GetKeyName(e.key.keysym.sym) << "\n";
      }
    }

    draw();
  }
}
