cmake_minimum_required(VERSION 3.14)
project(BullsAndCows)

# Add the executable for the test
add_executable(test_bulls_n_cows test_bulls_n_cows.cpp)
# Link the Google Test libraries
target_link_libraries(test_bulls_n_cows ${GTEST_LIBRARIES} pthread)

# Add the tests to CTest so that you can run 'make test' or 'ctest' from the build directory
# If you run 'ctest -R TestName', it will run just test with name TestName
# Add '-V' to see in verbose mode
add_test(NAME test_bulls_n_cows COMMAND test_bulls_n_cows)