cmake_minimum_required(VERSION 3.14)
project(SortVowels)

# Add the executable for the test
add_executable(test_sort_vowels test_sort_vowels.cpp)
# Link the Google Test libraries
target_link_libraries(test_sort_vowels ${GTEST_LIBRARIES} pthread)

# Add the tests to CTest so that you can run 'make test' or 'ctest' from the build directory
# If you run 'ctest -R TestName', it will run just test with name TestName
# Add '-V' to see in verbose mode
add_test(NAME test_sort_vowels COMMAND test_sort_vowels)