#include "vkplayground/Graphics/Vulkan/VulkanRenderer.hpp"

#include "vkplayground/Error/Error.hpp"

#include <expected>

namespace vkplayground {
namespace graphics {
VulkanRenderer::VulkanRenderer() : Backend() {}
VulkanRenderer::~VulkanRenderer() {}
std::expected<void, error::ErrorCodes> VulkanRenderer::initialize() {

  auto CreateVulkanInstance = Backend.createVulkanInstance();

  if (!CreateVulkanInstance) {
    return error::fail(CreateVulkanInstance.error());
  }

  return {};
};
} // namespace graphics
} // namespace vkplayground
