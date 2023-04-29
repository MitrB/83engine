#include "engine/engine.h"
#include "renderer/opengl/ogl_renderer.h"
#include "renderer/renderer.h"
#include "renderer/vulkan/vk_renderer.h"

#include <iostream>

int main(int argc, char *argv[]) {

  eightthreeegnine::Engine engine;

  eightthreeegnine::OpenGlRenderer renderer;

  engine.setRenderer(renderer);

  engine.run();

  return 0;
}