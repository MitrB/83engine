#pragma once

#include "../renderer.h"
#include <SDL2/SDL_video.h>

namespace eightthreeegnine {
class OpenGlRenderer : public eightthreeegnine::Renderer {
public:
  SDL_WindowFlags getWindowFlags();
};
} // namespace eightthreeegnine