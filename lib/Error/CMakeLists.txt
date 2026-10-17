set(INCLUDE_ROOT "${PROJECT_SOURCE_DIR}/include/vkplayground/Error")

target_sources(vkplayground
    PRIVATE
        ${INCLUDE_ROOT}/Error.hpp
)
