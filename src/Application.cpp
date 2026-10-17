#include "vkplayground/Window/WindowManager.hpp"

#include <iostream>

int main() {
    vkplayground::window::WindowManager window_manager;

    window_manager.initialize();

    std::cin.get();
    return 0;
}
