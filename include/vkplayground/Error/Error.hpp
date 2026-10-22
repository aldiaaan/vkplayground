#ifndef VK_PLAYGROUND_ERROR_ERROR_HPP
#define VK_PLAYGROUND_ERROR_ERROR_HPP

#include <cstdint>
#include <expected>
#include <string_view>
namespace vkplayground {
namespace error {

enum class ErrorCodes : uint8_t {
  FAILED_TO_CREATE_WINDOW,
  FAIELED_TO_INITIALIZE_SDL,

  FAILED_TO_CREATE_VULKAN_INSTANCE,
  FAILED_TO_QUERY_VALIDATION_LAYERS,
  FAILED_TO_QUERY_INSTANCE_EXTENSIONS,
  FAILED_TO_QUERY_AVAILABLE_LAYERS,
  FAILED_TO_QUERY_SDL_INSTANCE_EXTENSIONS
};

[[nodiscard]] constexpr auto fail(ErrorCodes c) noexcept { return std::unexpected(c); }

[[nodiscard]] constexpr std::string_view toString(ErrorCodes code) noexcept {
  using enum ErrorCodes;

  switch (code) {
  case FAILED_TO_CREATE_WINDOW:
    return "Failed to create Window";
  case FAIELED_TO_INITIALIZE_SDL:
    return "Failed to initialize SDL";
  case FAILED_TO_QUERY_AVAILABLE_LAYERS:
    return "Failed to query available layers";
  case FAILED_TO_QUERY_SDL_INSTANCE_EXTENSIONS:
    return "Failed to query instance extensions from sdl3";
  case FAILED_TO_CREATE_VULKAN_INSTANCE:
    return "Failed to create Vulkan instance";
  case FAILED_TO_QUERY_VALIDATION_LAYERS:
    return "Failed to query validation layers";
  case FAILED_TO_QUERY_INSTANCE_EXTENSIONS:
    return "Failed to query instance extensions";
  };

  return "Unknown error code";
}

} // namespace error
} // namespace vkplayground

#endif
