#include "push_pop_stack_target_n.cpp"
#include <gtest/gtest.h>
#include <string>
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

class TestPushPopStackTargetN : public ::testing::Test {
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


TEST_F(TestPushPopStackTargetN, test1_Push) { 
    vector<int> target = {1};
    int n = 3;
    vector<string> expected = {"Push"};
    vector<string> result = solution->buildArray(target, n);

    ASSERT_EQ(expected, result);
}

TEST_F(TestPushPopStackTargetN, test2_PushPush) { 
    vector<int> target = {1, 2};
    int n = 3;
    vector<string> expected = {"Push", "Push"};
    vector<string> result = solution->buildArray(target, n);

    ASSERT_EQ(expected, result);
}

TEST_F(TestPushPopStackTargetN, test3_PushPushPopPush) { 
    vector<int> target = {1, 3};
    int n = 3;
    vector<string> expected = {"Push", "Push", "Pop", "Push"};
    vector<string> result = solution->buildArray(target, n);

    ASSERT_EQ(expected, result);
}

TEST_F(TestPushPopStackTargetN, test4_PushPopPush) { 
    vector<int> target = {2};
    int n = 3;
    vector<string> expected = {"Push", "Pop", "Push"};
    vector<string> result = solution->buildArray(target, n);

    ASSERT_EQ(expected, result);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    // Adds the custom listener to the end. Google Test takes the ownership.
    ::testing::TestEventListeners& listeners = ::testing::UnitTest::GetInstance()->listeners();
    listeners.Append(new CustomTestListener);

    return RUN_ALL_TESTS();
}