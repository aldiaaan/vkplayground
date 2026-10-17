#ifndef VK_PLAYGROUND_GRAPHICS_VULKAN_VULKAN_RENDERER_HPP
#define VK_PLAYGROUND_GRAPHICS_VULKAN_VULKAN_RENDERER_HPP

#include "vkplayground/Graphics/Renderer.hpp"
#include "vkplayground/Graphics/Vulkan/VulkanBackend.hpp"

namespace vkplayground {
namespace graphics {
class VulkanRenderer : public Renderer {
  public:
    VulkanRenderer();
    ~VulkanRenderer();

    std::expected<void, error::ErrorCodes> initialize() override;

  private:
    VulkanBackend Backend;
};
} // namespace graphics
} // namespace vkplayground

#endif
