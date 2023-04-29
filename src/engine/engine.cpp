#include "engine.h"

#include <cstdio>
#include <iostream>
#include <iterator>

namespace eightthreeegnine {

void Engine::run() {
  bool quit = false;
  renderer.init();
  while (!quit) {
    // for (int i = 0; i < std::size(renderer.vertices); i++) {
    //   renderer.vertices[i] += 0.001f;
    //   std::cout << renderer.vertices[i] << "\n";
    // }
    quit = renderer.run();
  }
  renderer.cleanup();
}

void Engine::setRenderer(OpenGlRenderer given_renderer) {
  this->renderer = given_renderer;
}

} // namespace eightthreeegnine

