add_library(vkplayground STATIC "")
add_library(vkplayground::vkplayground ALIAS vkplayground)

target_include_directories(
  vkplayground
  PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/vkplayground>)

set_target_properties(vkplayground PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory(Math)
add_subdirectory(Graphics)
