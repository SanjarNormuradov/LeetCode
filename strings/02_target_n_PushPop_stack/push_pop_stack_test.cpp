#include "target_n_PushPop_stack.cpp"
#include <gtest/gtest.h>
#include <string>
#include <vector>
 
using namespace std;


class BuildArrayTest : public ::testing::Test {
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


TEST_F(BuildArrayTest, Push) { 
    vector<string> stack = {"Push"};
    vector<int> target = {1};
    ASSERT_EQ(stack, solution->buildArray(target, 3));
}

TEST_F(BuildArrayTest, PushPush) { 
    vector<string> stack = {"Push", "Push"};
    vector<int> target = {1, 2};
    ASSERT_EQ(stack, solution->buildArray(target, 3));
}

TEST_F(BuildArrayTest, PushPushPopPush) { 
    vector<string> stack = {"Push", "Push", "Pop", "Push"};
    vector<int> target = {1, 3};
    ASSERT_EQ(stack, solution->buildArray(target, 3));
}

TEST_F(BuildArrayTest, PushPopPush) { 
    vector<string> stack = {"Push", "Pop", "Push"};
    vector<int> target = {2};
    ASSERT_EQ(stack, solution->buildArray(target, 3));
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}