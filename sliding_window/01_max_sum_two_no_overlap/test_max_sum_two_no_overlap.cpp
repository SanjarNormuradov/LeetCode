#include "max_sum_two_no_overlap.cpp"
#include <gtest/gtest.h>
#include <vector>
#include <chrono>
#include <iostream>
 
using namespace std;


// A simple struct to hold test results
struct TestResult {
    string test_name;
    chrono::duration<double> elapsed_time;
};

// Custom listener
class CustomTestListener : public ::testing::EmptyTestEventListener {
private:
    vector<TestResult> results;
    chrono::time_point<chrono::high_resolution_clock> start_time;

public:
    // Called before a test starts
    void OnTestStart(const ::testing::TestInfo& test_info) override {
        start_time = chrono::high_resolution_clock::now();
    }

    // Called after a test ends
    void OnTestEnd(const ::testing::TestInfo& test_info) override {
        auto end_time = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed_time = end_time - start_time;
        results.push_back({test_info.name(), elapsed_time});
    }

    // Called after all tests have run
    void OnTestProgramEnd(const ::testing::UnitTest& unit_test) override {
        // Now print all the results
        cout << "\nTest Time Results:\n\n";
        int nameWidth = 60;
        for (const auto& result : results) {
            cout << left << setw(nameWidth) << result.test_name 
                 << "time: " << scientific << setprecision(2) 
                 << result.elapsed_time.count() << " s\n";
        }
        cout << endl;
    }
};


class TestMaxSumTwoNoOverlap : public ::testing::Test {
protected:
    Solution* solution; // Each test will have its own pointer to Solution instance

    void SetUp() override {
        // Code here will be called immediately after the constructor 
        // (right before each test).
        solution = new Solution();
    }

    void TearDown() override {
        // Code here will be called immediately after each test 
        // (right before the destructor).
        delete solution;
    }
};


TEST_F(TestMaxSumTwoNoOverlap, test1_Len12) { 
    vector<int> nums = {0, 6, 5, 2, 2, 5, 1, 9, 4};
    int firstLen = 1;
    int secondLen = 2;
    int expected = 20;
    int result = solution->maxSumTwoNoOverlap(nums, firstLen, secondLen);

    ASSERT_EQ(expected, result);
}

TEST_F(TestMaxSumTwoNoOverlap, test2_Len32) { 
    vector<int> nums = {3, 8, 1, 3, 2, 1, 8, 9, 0};
    int firstLen = 3;
    int secondLen = 2;
    int expected = 29;
    int result = solution->maxSumTwoNoOverlap(nums, firstLen, secondLen);

    ASSERT_EQ(expected, result);
}

TEST_F(TestMaxSumTwoNoOverlap, test3_Len43) { 
    vector<int> nums = {2, 1, 5, 6, 0, 9, 5, 0, 3, 8};
    int firstLen = 4;
    int secondLen = 3;
    int expected = 31;
    int result = solution->maxSumTwoNoOverlap(nums, firstLen, secondLen);

    ASSERT_EQ(expected, result);
}

TEST_F(TestMaxSumTwoNoOverlap, test4_Len53) { 
    vector<int> nums = {4, 5, 14, 16, 16, 20, 7, 13, 8, 15};
    int firstLen = 5;
    int secondLen = 3;
    int expected = 109;
    int result = solution->maxSumTwoNoOverlap(nums, firstLen, secondLen);

    ASSERT_EQ(expected, result);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    // Adds the custom listener to the end. Google Test takes the ownership.
    ::testing::TestEventListeners& listeners = ::testing::UnitTest::GetInstance()->listeners();
    listeners.Append(new CustomTestListener);

    return RUN_ALL_TESTS();
}