add_library(vkplayground STATIC "")
add_library(vkplayground::vkplayground ALIAS vkplayground)

set_target_properties(vkplayground PROPERTIES LINKER_LANGUAGE CXX)

FetchContent_Declare(
  SDL3
  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
  GIT_TAG release-3.4.18)

FetchContent_MakeAvailable(SDL3)

target_link_libraries(vkplayground PRIVATE SDL3::SDL3)

target_include_directories(
  vkplayground
  PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/vkplayground>)

add_subdirectory(Error)
add_subdirectory(Engine)
add_subdirectory(Math)
add_subdirectory(Graphics)
add_subdirectory(Window)
