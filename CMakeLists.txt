cmake_minimum_required(VERSION 3.14)


project(SprawdzanieSubskrypcji VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add subdirectories
add_subdirectory(src)

include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# Now you can link against gtest or gtest_main as needed. Example:
add_executable(my_test_suite tests/test_project.cpp)
target_link_libraries(my_test_suite gtest_main)