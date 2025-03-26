cmake_minimum_required(VERSION 3.5)
project(NobleDesktop)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
        DOWNLOAD_EXTRACT_TIMESTAMP true
)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.0
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)
FetchContent_MakeAvailable(SFML)

enable_testing()

add_executable(
        NobleDesktopTests
        NobleDesktop.cpp
        NobleDesktop.h
        NobleVM/RuntimeFrame.cpp
        NobleVM/RuntimeFrame.h
        NobleVM/VirtualMachine.cpp
        NobleVM/VirtualMachine.h
)

target_link_libraries(
        NobleDesktopTests
        GTest::gtest_main
        SFML::Graphics
)

include(GoogleTest)
gtest_discover_tests(NobleDesktopTests)

add_executable(
        NobleDesktop
        main.cpp
        NobleDesktop.cpp
        NobleDesktop.h
        NobleVM/RuntimeFrame.cpp
        NobleVM/RuntimeFrame.h
        NobleVM/VirtualMachine.cpp
        NobleVM/VirtualMachine.h
)

target_link_libraries(
        NobleDesktop
        SFML::Graphics
)
