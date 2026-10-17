#ifndef VK_PLAYGROUND_ENGINE_ENGINE_HPP
#define VK_PLAYGROUND_ENGINE_ENGINE_HPP

#include "vkplayground/Error/Error.hpp"
#include "vkplayground/Window/WindowManager.hpp"

#include <expected>

namespace vkplayground {
namespace engine {

class Engine {
  public:
    Engine() : WindowManager() {}
    std::expected<void, error::ErrorCodes> initialize();

  private:
    window::WindowManager WindowManager;
};
} // namespace engine
} // namespace vkplayground

#endif
