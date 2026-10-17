add_library(vkplayground STATIC "")
add_library(vkplayground::vkplayground ALIAS vkplayground)

set_target_properties(vkplayground PROPERTIES LINKER_LANGUAGE CXX)

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
