cmake_minimum_required(VERSION 3.14)
project(FloodFill)

# Add the executable for the test
add_executable(test_flood_fill test_flood_fill.cpp)
# Link the Google Test libraries
target_link_libraries(test_flood_fill ${GTEST_LIBRARIES} pthread)

# Add the tests to CTest so that you can run 'make test' or 'ctest' from the build directory
# If you run 'ctest -R TestName', it will run just test with name TestName
# Add '-V' to see in verbose mode
add_test(NAME test_flood_fill COMMAND test_flood_fill)