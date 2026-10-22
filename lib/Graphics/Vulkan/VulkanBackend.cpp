#include "vkplayground/Graphics/Vulkan/VulkanBackend.hpp"

#include "SDL3/SDL_stdinc.h"
#include "SDL3/SDL_vulkan.h"
#include "vkplayground/Error/Error.hpp"
#include "vkplayground/Log/Log.hpp"
#include "vulkan/vulkan.hpp"

#include <expected>
#include <vector>
#include <vulkan/vulkan.hpp>

namespace vkplayground {
namespace graphics {

VulkanBackend::VulkanBackend(const VulkanBackendConfig& Config) : EnableValidation(Config.EnableValidation) {}

std::expected<std::vector<const char*>, error::ErrorCodes> VulkanBackend::getRequiredExtensions() {
  std::vector<const char*> Extensions;

  Uint32 CountSDLExtensions;

  const char* const* SDLExtensions = SDL_Vulkan_GetInstanceExtensions(&CountSDLExtensions);

  if (!SDLExtensions) {
    return error::fail(error::ErrorCodes::FAILED_TO_QUERY_SDL_INSTANCE_EXTENSIONS);
  }

  Extensions.insert(Extensions.end(), SDLExtensions, SDLExtensions + CountSDLExtensions);

  auto LayerSupported = isLayerSupported("VK_LAYER_KHRONOS_validation");

  if (!LayerSupported) {
    return error::fail(LayerSupported.error());
  }

  if (LayerSupported.value() && EnableValidation) {
    auto ValidationExtensionSupported = isInstanceExtensionSupported(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
    if (!ValidationExtensionSupported) {
      return error::fail(ValidationExtensionSupported.error());
    }
    if (ValidationExtensionSupported.value()) {
      Extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
    }
  }

  return Extensions;
}

std::expected<std::vector<const char*>, error::ErrorCodes> VulkanBackend::getRequiredLayers() {
  std::vector<const char*> Layers = {};

  auto LayerSupported = isLayerSupported("VK_LAYER_KHRONOS_validation");

  if (!LayerSupported) {
    return error::fail(LayerSupported.error());
  }

  if (LayerSupported.value() && EnableValidation) {
    Layers.push_back("VK_LAYER_KHRONOS_validation");
  }

  return Layers;
}

std::expected<bool, error::ErrorCodes> VulkanBackend::isLayerSupported(std::string_view Name) {
  auto [Result, Layers] = vk::enumerateInstanceLayerProperties();

  if (Result != vk::Result::eSuccess) {
    return error::fail(error::ErrorCodes::FAILED_TO_QUERY_VALIDATION_LAYERS);
  }

  for (auto& Layer : Layers) {
    if (Name == Layer.layerName.data()) {
      return true;
    }
  }

  return false;
}

std::expected<bool, error::ErrorCodes> VulkanBackend::isInstanceExtensionSupported(std::string_view Name) {
  auto [Result, Extensions] = vk::enumerateInstanceExtensionProperties(nullptr);
  if (Result != vk::Result::eSuccess) {
    return error::fail(error::ErrorCodes::FAILED_TO_QUERY_INSTANCE_EXTENSIONS);
  }
  for (auto& Extension : Extensions) {
    if (Name == Extension.extensionName.data()) {
      return true;
    }
  }

  return false;
}

std::expected<void, error::ErrorCodes> VulkanBackend::createVulkanInstance() {

  LOG_INFO("Creating vulkan instance");
  LOG_INFO("  Debug enabled: {}", EnableValidation);

  vk::ApplicationInfo AppInfo{};
  AppInfo.sType = vk::StructureType::eApplicationInfo;
  AppInfo.pApplicationName = "Vulkan Playground";
  AppInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
  AppInfo.pEngineName = "vkplayground";
  AppInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
  AppInfo.apiVersion = VK_API_VERSION_1_4;

  vk::InstanceCreateInfo CreateInfo{};
  CreateInfo.sType = vk::StructureType::eInstanceCreateInfo;
  CreateInfo.pApplicationInfo = &AppInfo;

  CreateInfo.enabledLayerCount = 0;

  auto QuerySupportedValidationLayersResult = getRequiredLayers();

  if (!QuerySupportedValidationLayersResult) {
    return error::fail(QuerySupportedValidationLayersResult.error());
  }

  LOG_INFO("  Enabled layers:");
  for (auto& RequiredLayer : QuerySupportedValidationLayersResult.value()) {
    LOG_INFO("    {}", RequiredLayer);
  }

  auto RequiredInstanceExtensionsResult = getRequiredExtensions();

  if (!RequiredInstanceExtensionsResult) {
    return error::fail(RequiredInstanceExtensionsResult.error());
  }

  LOG_INFO("  Enabled extensions:");
  for (auto& RequiredExtension : RequiredInstanceExtensionsResult.value()) {
    LOG_INFO("    {}", RequiredExtension);
  }

  CreateInfo.ppEnabledExtensionNames = RequiredInstanceExtensionsResult->data();
  CreateInfo.enabledExtensionCount = RequiredInstanceExtensionsResult->size();

  auto CreateInstanceResult = vk::createInstance(&CreateInfo, nullptr, &VulkanInstance);

  if (CreateInstanceResult != vk::Result::eSuccess) {
    return error::fail(error::ErrorCodes::FAILED_TO_CREATE_VULKAN_INSTANCE);
  }

  return {};
}
} // namespace graphics
} // namespace vkplayground
