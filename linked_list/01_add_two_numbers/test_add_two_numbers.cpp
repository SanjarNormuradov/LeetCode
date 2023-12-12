#include "add_two_numbers.cpp"
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


class TestAddTwoNumbers : public ::testing::Test {
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


TEST_F(TestAddTwoNumbers, test1_807) {
    ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    ListNode* result = solution->addTwoNumbers(l1, l2);
    ListNode* nextNode = nullptr;
    vector<int> expected = {7, 0, 8};
    for (auto& digit : expected) {
        nextNode = result->next;
        ASSERT_EQ(digit, result->val);
        delete result;
        result = nextNode;
    }
}

TEST_F(TestAddTwoNumbers, test2_0) {
    ListNode *l1 = new ListNode();
    ListNode *l2 = new ListNode();
    ListNode* result = solution->addTwoNumbers(l1, l2);
    ASSERT_EQ(0, result->val);
    delete result;
}

TEST_F(TestAddTwoNumbers, test3_10009998) {
    ListNode *l1 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
    ListNode *l2 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));
    ListNode* result = solution->addTwoNumbers(l1, l2);
    ListNode* nextNode = nullptr;
    vector<int> expected = {8, 9, 9, 9, 0, 0, 0, 1};
    for (auto& digit : expected) {
        nextNode = result->next;
        ASSERT_EQ(digit, result->val);
        delete result;
        result = nextNode;
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    // Adds the custom listener to the end. Google Test takes the ownership.
    ::testing::TestEventListeners& listeners = ::testing::UnitTest::GetInstance()->listeners();
    listeners.Append(new CustomTestListener);

    return RUN_ALL_TESTS();
}