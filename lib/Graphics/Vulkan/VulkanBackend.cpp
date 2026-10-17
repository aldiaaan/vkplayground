#include "vkplayground/Graphics/Vulkan/VulkanBackend.hpp"

#include "SDL3/SDL_log.h"
#include "SDL3/SDL_stdinc.h"
#include "SDL3/SDL_vulkan.h"
#include "vkplayground/Error/Error.hpp"
#include "vulkan/vulkan.hpp"

#include <cstdint>
#include <cstring>
#include <expected>
#include <vector>
#include <vulkan/vulkan.hpp>

namespace vkplayground {
namespace graphics {

VulkanBackend::VulkanBackend()
    : ValidationLayers{"VK_LAYER_KHRONOS_validation"} {}

std::expected<std::vector<const char*>, error::ErrorCodes>
VulkanBackend::querySupportedValidationLayers() {
    uint32_t LayerCount;
    auto EnumerateLayerCountResult =
        vk::enumerateInstanceLayerProperties(&LayerCount, nullptr);

    if (EnumerateLayerCountResult != vk::Result::eSuccess) {
        return error::fail(
            error::ErrorCodes::FAILED_TO_QUERY_VALIDATION_LAYERS);
    }

    std::vector<vk::LayerProperties> AvailableLayers(LayerCount);
    auto EnumerateAvailableLayersResult = vk::enumerateInstanceLayerProperties(
        &LayerCount, AvailableLayers.data());

    if (EnumerateAvailableLayersResult != vk::Result::eSuccess) {
        return error::fail(
            error::ErrorCodes::FAILED_TO_QUERY_VALIDATION_LAYERS);
    }

    std::vector<const char*> SupportedLayers;

    for (std::string Layer : ValidationLayers) {
        for (const auto& AvailableLayer : AvailableLayers) {
            if (strcmp(AvailableLayer.layerName, Layer.c_str()) == 0) {
                // SDL_Log("Found supported validation layer %s",
                // Layer.c_str());
                SupportedLayers.push_back(Layer.c_str());
            }
        }
    }

    return SupportedLayers;
};

std::expected<void, error::ErrorCodes> VulkanBackend::createVulkanInstance() {

    vk::ApplicationInfo AppInfo{};
    AppInfo.sType = vk::StructureType::eApplicationInfo;
    AppInfo.pApplicationName = "Vulkan Playground";
    AppInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    AppInfo.pEngineName = "vkplayground";
    AppInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    AppInfo.apiVersion = VK_API_VERSION_1_4;

    Uint32 CountInstanceExtensions;

    const char* const* InstanceExtensions =
        SDL_Vulkan_GetInstanceExtensions(&CountInstanceExtensions);

    vk::InstanceCreateInfo CreateInfo{};
    CreateInfo.sType = vk::StructureType::eInstanceCreateInfo;
    CreateInfo.pApplicationInfo = &AppInfo;
    CreateInfo.ppEnabledExtensionNames = InstanceExtensions;
    CreateInfo.enabledExtensionCount = CountInstanceExtensions;

    CreateInfo.enabledLayerCount = 0;

    auto QuerySupportedValidationLayersResult =
        querySupportedValidationLayers();

    if (!QuerySupportedValidationLayersResult) {
        return error::fail(QuerySupportedValidationLayersResult.error());
    }

    if (QuerySupportedValidationLayersResult->size() > 0) {
        CreateInfo.enabledLayerCount =
            QuerySupportedValidationLayersResult->size();
        CreateInfo.ppEnabledLayerNames =
            QuerySupportedValidationLayersResult->data();
    }

    if (vk::createInstance(&CreateInfo, nullptr, &VulkanInstance) !=
        vk::Result::eSuccess) {
        return error::fail(error::ErrorCodes::FAILED_TO_CREATE_VULKAN_INSTANCE);
    }

    return {};
}
} // namespace graphics
} // namespace vkplayground
