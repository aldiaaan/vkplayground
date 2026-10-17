#ifndef VK_PLAYGROUND_WINDOW_WINDOW_MANAGER_HPP
#define VK_PLAYGROUND_WINDOW_WINDOW_MANAGER_HPP

#include "vkplayground/Error/Error.hpp"

#include <expected>

struct SDL_Window;

namespace vkplayground {
namespace window {

class WindowManager {
  public:
    WindowManager() = default;

    ~WindowManager() noexcept;
    WindowManager(const WindowManager&) = delete;
    WindowManager& operator=(const WindowManager&) = delete;
    WindowManager(WindowManager&& other) noexcept;
    WindowManager& operator=(WindowManager&& other) noexcept;

    std::expected<void, error::ErrorCodes> initialize();

  private:
    SDL_Window* Window = nullptr;
};
} // namespace window
} // namespace vkplayground
#endif
