#include "vkplayground/Engine/Engine.hpp"

#include "vkplayground/Error/Error.hpp"

#include <expected>

namespace vkplayground {
namespace engine {

std::expected<void, error::ErrorCodes> Engine::initialize() {
    auto initializeWindowResult = WindowManager.initialize();

    if (!initializeWindowResult) {
        return initializeWindowResult;
    }

    return {};
}

} // namespace engine
} // namespace vkplayground
