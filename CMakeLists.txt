cmake_minimum_required(VERSION 3.14)
project(LeetCode)

# Enable testing with Google Test
enable_testing()

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Subdirectories for each category
add_subdirectory(arrays)
add_subdirectory(strings)
add_subdirectory(data_structures)
add_subdirectory(linked_list)
add_subdirectory(dynamic_programming)
add_subdirectory(sliding_window)
add_subdirectory(sorting)
add_subdirectory(binary_search)
add_subdirectory(divide_conquer)
