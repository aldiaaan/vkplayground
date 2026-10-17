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

WindowManager& WindowManager::operator=(WindowManager&& other) noexcept {
    if (this != &other) {
        if (Window) {
            SDL_DestroyWindow(Window);
        }
        Window = other.Window;
        other.Window = nullptr;
    }
    return *this;
}

WindowManager::WindowManager(WindowManager&& other) noexcept
    : Window(std::exchange(other.Window, nullptr)) {}

WindowManager::~WindowManager() noexcept {
    if (Window) {
        SDL_DestroyWindow(Window);
    };
}

} // namespace window
} // namespace vkplayground
