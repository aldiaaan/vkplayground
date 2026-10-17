#include "SDL3/SDL_log.h"
#include "vkplayground/Error/Error.hpp"
#define SDL_MAIN_USE_CALLBACKS

#include "SDL3/SDL_init.h"
#include "vkplayground/Engine/Engine.hpp"

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

SDL_AppResult SDL_AppInit(void** AppState, int Argc, char* Argv[]) {

    auto* Engine = new vkplayground::engine::Engine(
        vkplayground::engine::EngineOptions{.WindowTitle = "Learn Vulkan!",
                                            .WindowWidth = 1366,
                                            .windowHeight = 768});

    auto EngineInitializationResult = Engine->initialize();

    if (!EngineInitializationResult) {
        SDL_Log("%s", std::string(vkplayground::error::toString(
                                      EngineInitializationResult.error()))
                          .c_str());
        return SDL_APP_FAILURE;
    }

    *AppState = Engine;

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* AppState, SDL_Event* Event) {
    if (Event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;
    }
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void* AppState) { return SDL_APP_CONTINUE; }

void SDL_AppQuit(void* AppState, SDL_AppResult Result) {

    if (AppState) {
        delete static_cast<vkplayground::engine::Engine*>(AppState);
    }

    SDL_Quit();
}
