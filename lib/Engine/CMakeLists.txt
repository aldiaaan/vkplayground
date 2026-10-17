set(INCLUDE_ROOT "${PROJECT_SOURCE_DIR}/include/vkplayground/Engine")

target_sources(vkplayground
    PRIVATE
        ${INCLUDE_ROOT}/Engine.hpp
        Engine.cpp
)
