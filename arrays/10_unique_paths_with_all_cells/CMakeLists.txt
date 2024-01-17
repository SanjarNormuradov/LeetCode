cmake_minimum_required(VERSION 3.14)
project(TestUniquePathsWithAllCells)

# Add the executable for the test
add_executable(test_unique_paths_with_all_cells test_unique_paths_with_all_cells.cpp)
# Link the Google Test libraries
target_link_libraries(test_unique_paths_with_all_cells ${GTEST_LIBRARIES} pthread)

# Add the tests to CTest so that you can run 'make test' or 'ctest' from the build directory
# If you run 'ctest -R TestName', it will run just test with name TestName
# Add '-V' to see in verbose mode
add_test(NAME test_unique_paths_with_all_cells COMMAND test_unique_paths_with_all_cells)