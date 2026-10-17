#ifndef VK_PLAYGROUND_GRAPHICS_RENDERER_HPP
#define VK_PLAYGROUND_GRAPHICS_RENDERER_HPP

#include "vkplayground/Error/Error.hpp"

#include <expected>

namespace vkplayground {
namespace graphics {
class Renderer {
  public:
    virtual ~Renderer() = default;
    virtual std::expected<void, error::ErrorCodes> initialize() = 0;
    Renderer() = default;
};
} // namespace graphics
} // namespace vkplayground

#endif
