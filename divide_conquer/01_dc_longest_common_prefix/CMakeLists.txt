cmake_minimum_required(VERSION 3.14)
project(TestDCLongestCommonPrefix)

# Add the executable for the test
add_executable(test_dc_longest_common_prefix test_dc_longest_common_prefix.cpp)
# Link the Google Test libraries
target_link_libraries(test_dc_longest_common_prefix ${GTEST_LIBRARIES} pthread)

# Add the tests to CTest so that you can run 'make test' or 'ctest' from the build directory
# If you run 'ctest -R TestName', it will run just test with name TestName
# Add '-V' to see in verbose mode
add_test(NAME test_dc_longest_common_prefix COMMAND test_dc_longest_common_prefix)