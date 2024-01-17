cmake_minimum_required(VERSION 3.14)
project(TestPascalTriangle)

# Add the executable for the test
add_executable(test_pascal_triangle test_pascal_triangle.cpp)
# Link the Google Test libraries
target_link_libraries(test_pascal_triangle ${GTEST_LIBRARIES} pthread)

# Add the tests to CTest so that you can run 'make test' or 'ctest' from the build directory
# If you run 'ctest -R TestName', it will run just test with name TestName
# Add '-V' to see in verbose mode
add_test(NAME test_pascal_triangle COMMAND test_pascal_triangle)