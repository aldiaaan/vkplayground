set(INCLUDE_ROOT "${PROJECT_SOURCE_DIR}/include/vkplayground/Log")

FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG v1.17.0
)

FetchContent_MakeAvailable(spdlog)

target_sources(vkplayground
    PRIVATE
        ${INCLUDE_ROOT}/Log.hpp
)

target_link_libraries(vkplayground PRIVATE spdlog::spdlog)
