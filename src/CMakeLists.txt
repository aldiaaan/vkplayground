add_executable(application
    Application.cpp
)

target_link_libraries(application
    PRIVATE
        vkplayground
)
