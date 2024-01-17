cmake_minimum_required(VERSION 3.14)
project(RestoreFromAdjacentPairs)

# Add the executable for the test
add_executable(test_restore_from_pairs test_restore_from_pairs.cpp)
# Link the Google Test libraries
target_link_libraries(test_restore_from_pairs ${GTEST_LIBRARIES} pthread)

# Add the tests to CTest so that you can run 'make test' or 'ctest' from the build directory
# If you run 'ctest -R TestName', it will run just test with name TestName
# Add '-V' to see in verbose mode
add_test(NAME test_restore_from_pairs COMMAND test_restore_from_pairs)