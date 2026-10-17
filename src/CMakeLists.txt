add_executable(application
    Application.cpp
)

target_link_libraries(application
    PRIVATE
        vkplayground
)

if(VK_PLAYGROUND_PLATFORM MATCHES "WIN32")
    add_custom_command(TARGET application POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_RUNTIME_DLLS:application>
            $<TARGET_FILE_DIR:application>
        COMMAND_EXPAND_LISTS
    )
endif()
