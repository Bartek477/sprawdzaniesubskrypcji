cmake_minimum_required(VERSION 3.14)

project(SprawdzanieSubskrypcji VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Assuming external libraries and test files are correctly placed
# Add the subdirectory for PyBind11
add_subdirectory(external/pybind11)

##################################################################
# FetchContent for GoogleTest
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)
##################################################################

# Define the main executable
add_executable(${PROJECT_NAME} src/main.cpp)

# Link against PyBind11
target_link_libraries(${PROJECT_NAME} PRIVATE pybind11::embed)

# If you have additional source files, make sure to include them in the add_executable call for your main application

# Define your test executable after FetchContent_MakeAvailable for GoogleTest
# Ensure your tests directory exists and has test_project.cpp
add_executable(my_test_suite tests/test_project.cpp)
target_link_libraries(my_test_suite gtest_main)