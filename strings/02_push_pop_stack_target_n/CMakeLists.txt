cmake_minimum_required(VERSION 3.14)
project(PushPopStackTargetN)

# Add the executable for the test
add_executable(test_push_pop_stack_target_n test_push_pop_stack_target_n.cpp)
# Link the Google Test libraries
target_link_libraries(test_push_pop_stack_target_n ${GTEST_LIBRARIES} pthread)

# Add the tests to CTest so that you can run 'make test' or 'ctest' from the build directory
# If you run 'ctest -R TestName', it will run just test with name TestName
add_test(NAME test_push_pop_stack_target_n COMMAND test_push_pop_stack_target_n)