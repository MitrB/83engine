#pragma once
#include "../renderer.h"

namespace eightthreeegnine {
class VulkanRenderer : public eightthreeegnine::Renderer {

public:
  SDL_WindowFlags getWindowFlags();
};

} // namespace eightthreeegnine