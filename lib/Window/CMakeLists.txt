set(INCLUDE_ROOT "${PROJECT_SOURCE_DIR}/include/vkplayground/Window")

target_sources(vkplayground
    PRIVATE
        ${INCLUDE_ROOT}/WindowManager.hpp
        WindowManager.cpp
)
