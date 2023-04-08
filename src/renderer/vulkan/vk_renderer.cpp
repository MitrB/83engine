#include <SDL2/SDL_keyboard.h>
#include <iostream>

#include "inits.h"
#include "vk_renderer.h"
#include "types.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_vulkan.h>

namespace eightthreeegnine {
SDL_WindowFlags VulkanRenderer::getWindowFlags() {
  SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_VULKAN);
  return window_flags;
}
} // namespace eightthreeegnine