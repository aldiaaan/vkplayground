#ifndef VK_PLAYGROUND_ERROR_ERROR_HPP
#define VK_PLAYGROUND_ERROR_ERROR_HPP

#include <cstdint>
#include <expected>
#include <string_view>
namespace vkplayground {
namespace error {

enum class ErrorCodes : uint8_t {
    FAILED_TO_CREATE_WINDOW,
    FAIELED_TO_INITIALIZE_SDL
};

[[nodiscard]] constexpr auto fail(ErrorCodes c) noexcept {
    return std::unexpected(c);
}

[[nodiscard]] constexpr std::string_view toString(ErrorCodes code) noexcept {
    using enum ErrorCodes;

    switch (code) {
    case FAILED_TO_CREATE_WINDOW:
        return "Failed to create Window";
    case FAIELED_TO_INITIALIZE_SDL:
        return "Failed to initialize SDL";
    };

    return "Unknown error code";
}

} // namespace error
} // namespace vkplayground

#endif
