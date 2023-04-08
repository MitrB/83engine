#pragma once
#include "../renderer.h"
#include <SDL2/SDL_video.h>
#include <vulkan/vulkan.h>

namespace eightthreeegnine {
class VulkanRenderer : public eightthreeegnine::Renderer {

public:
  SDL_WindowFlags getWindowFlags();
};

} // namespace eightthreeegnine