#include "engine/engine.h"
#include "renderer/opengl/ogl_renderer.h"
#include "renderer/renderer.h"
#include "renderer/vulkan/vk_renderer.h"

#include <iostream>

int main(int argc, char *argv[]) {

  eightthreeegnine::OpenGlRenderer engine;

  engine.init();

  engine.run();

  engine.cleanup();

  return 0;
}