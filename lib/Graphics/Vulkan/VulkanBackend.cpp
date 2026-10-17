#include "vkplayground/Graphics/Vulkan/VulkanBackend.hpp"

#include "SDL3/SDL_log.h"
#include "SDL3/SDL_stdinc.h"
#include "SDL3/SDL_vulkan.h"
#include "vkplayground/Error/Error.hpp"

#include <cstdint>
#include <expected>
#include <vulkan/vulkan.hpp>

namespace vkplayground {
namespace graphics {

VulkanBackend::VulkanBackend() {}

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

    // for (Uint32 i = 0; i < CountInstanceExtensions; ++i) {
    //     SDL_Log("Extension: %s", InstanceExtensions[i]);
    // }

    if (vk::createInstance(&CreateInfo, nullptr, &VulkanInstance) !=
        vk::Result::eSuccess) {
        return error::fail(error::ErrorCodes::FAILED_TO_CREATE_VULKAN_INSTANCE);
    }

    return {};
}
} // namespace graphics
} // namespace vkplayground
