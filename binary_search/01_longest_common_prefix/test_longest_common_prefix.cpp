#include "merge_sorted_arrays.cpp"
#include <gtest/gtest.h>
#include <chrono>
#include <iostream>
#include <vector>
 
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


class TestMergeSortedArrays : public ::testing::Test {
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


TEST_F(TestMergeSortedArrays, test1_m3n3) { 
    vector<int> nums1 = {1, 2, 3, 0, 0, 0}, nums2 = {2, 5, 6};
    int m = 3, n = 3;
    vector<int> expected = {1, 2, 2, 3, 5, 6};
    solution->merge(nums1, m, nums2, n);

    ASSERT_EQ(expected, nums1);
}

TEST_F(TestMergeSortedArrays, test2_m1n0) { 
    vector<int> nums1 = {1}, nums2 = {};
    int m = 1, n = 0;
    vector<int> expected = {1};
    solution->merge(nums1, m, nums2, n);

    ASSERT_EQ(expected, nums1);
}

TEST_F(TestMergeSortedArrays, test3_m0n1) { 
    vector<int> nums1 = {0}, nums2 = {1};
    int m = 0, n = 1;
    vector<int> expected = {1};
    solution->merge(nums1, m, nums2, n);

    ASSERT_EQ(expected, nums1);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    // Adds the custom listener to the end. Google Test takes the ownership.
    ::testing::TestEventListeners& listeners = ::testing::UnitTest::GetInstance()->listeners();
    listeners.Append(new CustomTestListener);

    return RUN_ALL_TESTS();
}