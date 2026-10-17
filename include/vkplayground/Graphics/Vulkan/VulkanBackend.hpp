#ifndef VK_PLAYGROUND_GRAPHICS_VULKAN_VULKAN_BACKEND_HPP
#define VK_PLAYGROUND_GRAPHICS_VULKAN_VULKAN_BACKEND_HPP

#include "vkplayground/Error/Error.hpp"

#include <expected>
#include <vulkan/vulkan.hpp>

namespace vkplayground {
namespace graphics {

class VulkanBackend {
public:
  VulkanBackend();

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
  std::expected<std::vector<const char*>, error::ErrorCodes> querySupportedValidationLayers();

private:
  vk::Instance VulkanInstance = nullptr;
  std::vector<std::string> ValidationLayers;
};
} // namespace graphics
} // namespace vkplayground

#endif
