cmake_minimum_required(VERSION 3.14)
project(CountIncreasingPath)

# Add the executable for the test
add_executable(test_count_increasing_path test_count_increasing_path.cpp)
# Link the Google Test libraries
target_link_libraries(test_count_increasing_path ${GTEST_LIBRARIES} pthread)

# Add the tests to CTest so that you can run 'make test' or 'ctest' from the build directory
# If you run 'ctest -R TestName', it will run just test with name TestName
# Add '-V' to see in verbose mode
add_test(NAME test_count_increasing_path COMMAND test_count_increasing_path)