#include "vkplayground/Window/WindowManager.hpp"

#include "SDL3/SDL_video.h"
#include "vkplayground/Error/Error.hpp"

#include <expected>
#include <utility>

namespace vkplayground {
namespace window {

std::expected<void, error::ErrorCodes> WindowManager::initialize() {
    if (!Window) {
        Window = SDL_CreateWindow("SDL Example", 1366, 768, SDL_WINDOW_VULKAN);
        if (!Window) {
            return std::unexpected(error::ErrorCodes::FAILED_TO_CREATE_WINDOW);
        }
    };

    return {};
}

WindowManager& WindowManager::operator=(WindowManager&& Other) noexcept {
    if (this != &Other) {
        if (Window) {
            SDL_DestroyWindow(Window);
        }
        Window = Other.Window;
        Other.Window = nullptr;
    }
    return *this;
}

WindowManager::WindowManager(WindowManager&& Other) noexcept
    : Window(std::exchange(Other.Window, nullptr)) {}

WindowManager::~WindowManager() noexcept {
    if (Window) {
        SDL_DestroyWindow(Window);
    };
}

} // namespace window
} // namespace vkplayground
