#include "vkplayground/Engine/Engine.hpp"

#include "SDL3/SDL_init.h"
#include "vkplayground/Error/Error.hpp"
#include "vkplayground/Window/WindowManager.hpp"

#include <expected>

namespace vkplayground {
namespace engine {

Engine::~Engine() noexcept {};

std::expected<void, error::ErrorCodes> Engine::initialize() {

    auto SDLInitResult =
        SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_JOYSTICK);

    if (!SDLInitResult) {
        return error::fail(error::ErrorCodes::FAIELED_TO_INITIALIZE_SDL);
    }

    auto initializeWindowResult = WindowManager.initialize(
        window::WindowManagerInitializeOptions{.Title = &Options.WindowTitle,
                                               .Width = Options.WindowWidth,
                                               .Height = Options.windowHeight});

    if (!initializeWindowResult) {
        return initializeWindowResult;
    }

    return {};
}

} // namespace engine
} // namespace vkplayground
