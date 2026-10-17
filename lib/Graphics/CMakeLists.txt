set(INCLUDE_ROOT "${PROJECT_SOURCE_DIR}/include/vkplayground/Graphics")

target_sources(vkplayground
    PRIVATE
        ${INCLUDE_ROOT}/Renderer.hpp
        Renderer.cpp
)

add_subdirectory(Vulkan)
