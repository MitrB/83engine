/**
 * @file renderer.h
 * @author Dmitry Buggenhout
 * @brief Renderer Abstraction
 * @version 0.1
 * @date 2023-04-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#include <SDL2/SDL_video.h>
#include <iostream>

namespace eightthreeegnine {
class Renderer {
public:
  int width = 640;
  int height = 360;

  SDL_Window *_window{nullptr};

  // initializes everything in the engine
  void init();

  // shuts down the engine
  void cleanup();

  // draw loop
  void draw();

  // run main loop
  void run();

  /**
   * @brief Get the Window Flags object
   * 
   * @return SDL_WindowFlags 
   */
  virtual SDL_WindowFlags getWindowFlags() {return {};};

  /**
   * @brief Resize callback to SDL window
   * 
   * @param window 
   * @param width 
   * @param height 
   */
  virtual void framebuffer_size_callback(SDL_Window *window, int width, int height);

};
} // namespace eightthreeegnine