FetchContent_MakeAvailable(googletest)

include(GoogleTest)

add_executable(unit_tests "")

add_subdirectory("Graphics")

target_include_directories(unit_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(unit_tests PRIVATE
    vkplayground
    GTest::gmock_main
)

gtest_discover_tests(unit_tests)
