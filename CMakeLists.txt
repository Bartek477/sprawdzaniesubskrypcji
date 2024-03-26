cmake_minimum_required(VERSION 3.14)
project(YourProject VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# PyBind11
add_subdirectory(external/pybind11)

# Main application
add_executable(${PROJECT_NAME} 
    src/main.cpp
    src/InputHandler.cpp
    src/HtmlParser.cpp
    src/DataProcessor.cpp
    src/ExcelWriter.cpp
    src/OutputHandler.cpp
)

# Link PyBind11
target_link_libraries(${PROJECT_NAME} PRIVATE pybind11::embed)

# Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable testing functionalities
enable_testing()

# Define your test executable
add_executable(tests 
    tests/InputHandlerTest.cpp
    tests/ExcelWriterTest.cpp
)

# Link test executable against gtest
target_link_libraries(tests PRIVATE gtest_main pybind11::embed)

include(GoogleTest)
gtest_discover_tests(tests)
