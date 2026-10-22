#ifndef VK_PLAYGROUND_GRAPHICS_VULKAN_VULKAN_BACKEND_HPP
#define VK_PLAYGROUND_GRAPHICS_VULKAN_VULKAN_BACKEND_HPP

#include "vkplayground/Error/Error.hpp"

#include <expected>
#include <vulkan/vulkan.hpp>

namespace vkplayground {
namespace graphics {

struct VulkanBackendConfig {
  bool EnableValidation = true;
};

class VulkanBackend {
public:
  explicit VulkanBackend(const VulkanBackendConfig& config = {});

  ~VulkanBackend() = default;

  VulkanBackend(const VulkanBackend&) = delete;
  VulkanBackend& operator=(const VulkanBackend&) = delete;

  VulkanBackend(VulkanBackend&& other) noexcept {}
  VulkanBackend& operator=(VulkanBackend&& other) noexcept {
    if (this != &other) {
    }
    return *this;
  }

  std::expected<void, error::ErrorCodes> createVulkanInstance();

private:
  std::expected<std::vector<const char*>, error::ErrorCodes> getRequiredLayers();
  std::expected<std::vector<const char*>, error::ErrorCodes> getRequiredExtensions();
  std::expected<bool, error::ErrorCodes> isInstanceExtensionSupported(std::string_view Name);
  std::expected<bool, error::ErrorCodes> isLayerSupported(std::string_view Name);

  vk::Instance VulkanInstance = nullptr;
  bool EnableValidation = false;
  // std::vector<std::string> Layers;
  // std::vector<std::string> Extensions;
};
} // namespace graphics
} // namespace vkplayground

#endif
