cmake_minimum_required(VERSION 3.14)
project(TestBFSShortestPathBinaryMatrix)

# Add the executable for the test
add_executable(test_bfs_shortest_path_binary_matrix test_bfs_shortest_path_binary_matrix.cpp)
# Link the Google Test libraries
target_link_libraries(test_bfs_shortest_path_binary_matrix ${GTEST_LIBRARIES} pthread)

# Add the tests to CTest so that you can run 'make test' or 'ctest' from the build directory
# If you run 'ctest -R TestName', it will run just test with name TestName
# Add '-V' to see in verbose mode
add_test(NAME test_bfs_shortest_path_binary_matrix COMMAND test_bfs_shortest_path_binary_matrix)