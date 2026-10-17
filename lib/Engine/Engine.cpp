#include "vkplayground/Engine/Engine.hpp"

#include "SDL3/SDL_init.h"
#include "vkplayground/Error/Error.hpp"
#include "vkplayground/Graphics/Vulkan/VulkanRenderer.hpp"
#include "vkplayground/Log/Log.hpp"
#include "vkplayground/Window/WindowManager.hpp"

#include <expected>
#include <memory>

namespace vkplayground {
namespace engine {

Engine::Engine(EngineOptions Options)
    : Options(Options),
      Renderer(std::make_unique<graphics::VulkanRenderer>()) {};

Engine::~Engine() noexcept {};

std::expected<void, error::ErrorCodes> Engine::initialize() {

    auto SDLInitResult =
        SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_JOYSTICK);

    if (!SDLInitResult) {
        return error::fail(error::ErrorCodes::FAIELED_TO_INITIALIZE_SDL);
    }

    auto InitializeWindowResult = WindowManager.initialize(
        window::WindowManagerInitializeOptions{.Title = &Options.WindowTitle,
                                               .Width = Options.WindowWidth,
                                               .Height = Options.windowHeight});

    if (!InitializeWindowResult) {
        return error::fail(InitializeWindowResult.error());
    }

    auto InitializeRendererResult = Renderer->initialize();

    if (!InitializeRendererResult) {
        return error::fail(InitializeRendererResult.error());
    }

    return {};
}

} // namespace engine
} // namespace vkplayground
