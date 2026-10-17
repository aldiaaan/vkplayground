#ifndef VK_PLAYGROUND_WINDOW_WINDOW_MANAGER_HPP
#define VK_PLAYGROUND_WINDOW_WINDOW_MANAGER_HPP

#include "vkplayground/Error/Error.hpp"

#include <expected>
#include <string>

struct SDL_Window;

namespace vkplayground {
namespace window {

struct WindowManagerInitializeOptions {
    std::string* Title;
    int Width;
    int Height;
};

class WindowManager {
  public:
    WindowManager() = default;

    ~WindowManager() noexcept;
    WindowManager(const WindowManager&) = delete;
    WindowManager& operator=(const WindowManager&) = delete;
    WindowManager(WindowManager&& Other) noexcept;
    WindowManager& operator=(WindowManager&& Other) noexcept;

    std::expected<void, error::ErrorCodes>
    initialize(WindowManagerInitializeOptions Options);

  private:
    SDL_Window* Window = nullptr;
};
} // namespace window
} // namespace vkplayground
#endif
