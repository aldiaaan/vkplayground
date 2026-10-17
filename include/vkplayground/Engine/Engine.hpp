#ifndef VK_PLAYGROUND_ENGINE_ENGINE_HPP
#define VK_PLAYGROUND_ENGINE_ENGINE_HPP

#include "vkplayground/Error/Error.hpp"
#include "vkplayground/Graphics/Renderer.hpp"
#include "vkplayground/Window/WindowManager.hpp"

#include <expected>
#include <memory>
#include <string>

namespace vkplayground {
namespace engine {

struct EngineOptions {
  std::string WindowTitle = "";
  int WindowWidth = 1366;
  int windowHeight = 768;
};

class Engine {
public:
  Engine(EngineOptions Options);

  std::expected<void, error::ErrorCodes> initialize();
  ~Engine() noexcept;

private:
  EngineOptions Options;
  window::WindowManager WindowManager;
  std::unique_ptr<graphics::Renderer> Renderer;
};
} // namespace engine
} // namespace vkplayground

#endif
