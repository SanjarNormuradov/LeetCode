# cmake_minimum_required(VERSION 3.14)
# project(TestBTInorderTraversal)

# # Add the executable for the test
# add_executable(bt_inorder_traversal bt_inorder_traversal.cpp)
# # Link the Google Test libraries
# target_link_libraries(bt_inorder_traversal ${GTEST_LIBRARIES} pthread)

# # Add the tests to CTest so that you can run 'make test' or 'ctest' from the build directory
# # If you run 'ctest -R TestName', it will run just test with name TestName
# # Add '-V' to see in verbose mode
# add_test(NAME bt_inorder_traversal COMMAND bt_inorder_traversal)