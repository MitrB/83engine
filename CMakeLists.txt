cmake_minimum_required(VERSION 3.26.2)

project(83engine)

add_subdirectory(third_party)

find_package(Vulkan REQUIRED)
find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)

file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

# fetching SDL2
include(FetchContent)

FetchContent_Declare(
  SDL2
  URL https://www.libsdl.org/release/SDL2-2.0.20.tar.gz
  URL_HASH MD5=a53acc02e1cca98c4123229069b67c9e)

FetchContent_MakeAvailable(SDL2)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2::SDL2main)

if(WIN32)
  # copy the SDL2.dll to the same folder as the executable
  add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:SDL2::SDL2>
            $<TARGET_FILE_DIR:${PROJECT_NAME}>
    VERBATIM)
endif()

