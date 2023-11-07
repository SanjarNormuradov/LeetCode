#include "flood_fill.cpp"
#include <gtest/gtest.h>
#include <vector>
 
using namespace std;


class FloodFillTest : public ::testing::Test {
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


TEST_F(FloodFillTest, SimpleCase) { 
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1, sc = 1, newColor = 2;
    vector<vector<int>> expected = {{2, 2, 2}, {2, 2, 0}, {2, 0, 1}};

    ASSERT_EQ(expected, solution->floodFill(image, sr, sc, newColor));
}

TEST_F(FloodFillTest, SameStartColor) { 
    vector<vector<int>> image = {{0, 1, 2}, {3, 4, 5}};
    int sr = 0, sc = 0, newColor = 0;
    vector<vector<int>> expected = {{0, 1, 2}, {3, 4, 5}};

    ASSERT_EQ(expected, solution->floodFill(image, sr, sc, newColor));
}

TEST_F(FloodFillTest, ComplexCase) { 
    vector<vector<int>> image = {{6, 5, 1}, {2, 1, 1}, {1, 1, 3}, {1, 0, 1}};
    int sr = 2, sc = 1, newColor = 7;
    vector<vector<int>> expected = {{6, 5, 7}, {2, 7, 7}, {7, 7, 3}, {7, 0, 1}};

    ASSERT_EQ(expected, solution->floodFill(image, sr, sc, newColor));
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}