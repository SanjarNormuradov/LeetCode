cmake_minimum_required(VERSION 3.14)
project(TestMergeSortedArrays)

# Add the executable for the test
add_executable(test_merge_sorted_arrays test_merge_sorted_arrays.cpp)
# Link the Google Test libraries
target_link_libraries(test_merge_sorted_arrays ${GTEST_LIBRARIES} pthread)

# Add the tests to CTest so that you can run 'make test' or 'ctest' from the build directory
# If you run 'ctest -R TestName', it will run just test with name TestName
# Add '-V' to see in verbose mode
add_test(NAME test_merge_sorted_arrays COMMAND test_merge_sorted_arrays)