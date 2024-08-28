#include "bt_traversal.cpp"
#include <gtest/gtest.h>
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


class TestBTTraversal : public ::testing::Test {
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


TEST_F(TestBTTraversal, test1_InOrder1) {
    vector<int> root = {1, -1000, 2, 3};
    TreeNode *rootNode = solution->insertLevelOrder(root);
    vector<int> expected = {1, 3, 2};
    vector<int> result = solution->inorderTraversal(rootNode);
    ASSERT_EQ(expected, result);
}

TEST_F(TestBTTraversal, test2_InOrder2) {
    vector<int> root = {};
    TreeNode *rootNode = solution->insertLevelOrder(root);
    vector<int> expected = {};
    vector<int> result = solution->inorderTraversal(rootNode);
    ASSERT_EQ(expected, result);
}

TEST_F(TestBTTraversal, test3_InOrder3) {
    vector<int> root = {1};
    TreeNode *rootNode = solution->insertLevelOrder(root);
    vector<int> expected = {1};
    vector<int> result = solution->inorderTraversal(rootNode);
    ASSERT_EQ(expected, result);
}

TEST_F(TestBTTraversal, test4_InOrder4) {
    vector<int> root = {1, 5, 2, 6, -1000, 3, 4};
    TreeNode *rootNode = solution->insertLevelOrder(root);
    vector<int> expected = {6, 5, 1, 3, 2, 4};
    vector<int> result = solution->inorderTraversal(rootNode);
    ASSERT_EQ(expected, result);
}

TEST_F(TestBTTraversal, test5_PreOrder1) {
    vector<int> root = {1, 5, 2, 6, -1000, 3, 4};
    TreeNode *rootNode = solution->insertLevelOrder(root);
    vector<int> expected = {1, 5, 6, 2, 3, 4};
    vector<int> result = solution->preorderTraversal(rootNode);
    ASSERT_EQ(expected, result);
}

TEST_F(TestBTTraversal, test6_PostOrder1) {
    vector<int> root = {1, 5, 2, 6, -1000, 3, 4};
    TreeNode *rootNode = solution->insertLevelOrder(root);
    vector<int> expected = {6, 5, 3, 4, 2, 1};
    vector<int> result = solution->postorderTraversal(rootNode);
    ASSERT_EQ(expected, result);
}

TEST_F(TestBTTraversal, test7_LevelOrder1) {
    vector<int> root = {1, 5, 2, 6, -1000, 3, 4};
    TreeNode *rootNode = solution->insertLevelOrder(root);
    vector<vector<int>> expected = {{1}, {5, 2}, {6, 3, 4}};
    vector<vector<int>> result = solution->levelorderTraversal(rootNode);
    ASSERT_EQ(expected, result);
}

TEST_F(TestBTTraversal, test8_LevelOrder2) {
    vector<int> root = {0, 2, 4, 1, -1000, 3, -1, 5, 1, -1000, 6, -1000, 8};
    TreeNode *rootNode = solution->insertLevelOrder(root);
    vector<vector<int>> expected = {{0}, {2, 4}, {1, 3, -1}, {5, 1, 6, 8}};
    vector<vector<int>> result = solution->levelorderTraversal(rootNode);
    ASSERT_EQ(expected, result);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    // Adds the custom listener to the end. Google Test takes the ownership.
    ::testing::TestEventListeners& listeners = ::testing::UnitTest::GetInstance()->listeners();
    listeners.Append(new CustomTestListener);

    return RUN_ALL_TESTS();
}