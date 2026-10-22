set(INCLUDE_ROOT "${PROJECT_SOURCE_DIR}/include/vkplayground/Graphics/Vulkan")

target_sources(vkplayground
    PRIVATE
        ${INCLUDE_ROOT}/VulkanRenderer.hpp
        ${INCLUDE_ROOT}/VulkanBackend.hpp
        VulkanBackend.cpp
        VulkanRenderer.cpp
)

find_package(Vulkan REQUIRED)
target_compile_definitions(vkplayground PRIVATE VULKAN_HPP_NO_EXCEPTIONS)
target_link_libraries(vkplayground PRIVATE Vulkan::Vulkan)
