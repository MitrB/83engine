#include "ogl_renderer.h"
#include "../../../third_party/glad/include/glad/glad.h"
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

namespace eightthreeegnine {

const char *vertexShaderSource =
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

const char *fragmentShaderSource = "#version 330 core\n"
                                   "out vec4 FragColor;\n"
                                   "void main()\n"
                                   "{\n"
                                   "FragColor = vec4(0.2f, 0.8f, 0.5f, 1.0f);\n"
                                   "}\0";

const char *fragmentShaderSource2 = "#version 330 core\n"
                                   "out vec4 FragColor;\n"
                                   "void main()\n"
                                   "{\n"
                                   "FragColor = vec4(0.9f, 0.2f, 0.5f, 1.0f);\n"
                                   "}\0";

SDL_WindowFlags OpenGlRenderer::getWindowFlags() {

  SDL_WindowFlags window_flags =
      (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
  return window_flags;
}

void OpenGlRenderer::draw() {

  glClearColor(0.8f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glUseProgram(shaderProgram);
  glBindVertexArray(VAO);

  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

  glUseProgram(shaderProgram2);
  glBindVertexArray(VAO);

  glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
  // glDrawArrays(GL_TRIANGLES, 0, 3);

  SDL_GL_SwapWindow(_window);
}

int OpenGlRenderer::initGlad() {

  // SDL_GL_GetProcAddress get's OS specific OpenGL function
  if (!gladLoadGLLoader(SDL_GL_GetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return 1;
  }
  return 0;
}

void OpenGlRenderer::init() {
  // Request an OpenGL 4.6 context (should be core)
  SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
  // Also request a depth buffer
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

  Renderer::init();
  maincontext = SDL_GL_CreateContext(_window);
  initGlad();

  // Remember in OpenGl the first 2 parameters are the LOWER-LEFT CORNER coords
  glViewport(0, 0, 640, 360); // setting the dimentions for the viewport

  // vertex shader
  unsigned int vertexShader;
  vertexShader = glCreateShader(GL_VERTEX_SHADER);

  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);

  // checking if vertex shader compiled correctly
  int success;
  char infoLog[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

  if (!success) {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
              << infoLog << std::endl;
  }

  unsigned int fragmentShader;
  fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);

  unsigned int fragmentShader2;
  fragmentShader2 = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader2, 1, &fragmentShaderSource2, NULL);
  glCompileShader(fragmentShader2);

  shaderProgram = glCreateProgram();

  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);

  shaderProgram2 = glCreateProgram();  
  glAttachShader(shaderProgram2, vertexShader);
  glAttachShader(shaderProgram2, fragmentShader2);
  glLinkProgram(shaderProgram2);

  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
  glDeleteShader(fragmentShader2);

  // creating buffer
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
               GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, 0); 
  glBindVertexArray(0);  

  // WireFrame mode
  // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

}

void OpenGlRenderer::cleanup() {
  Renderer::cleanup();

  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteBuffers(1, &EBO);
  glDeleteProgram(shaderProgram);
}
} // namespace eightthreeegnine