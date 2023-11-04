/*
PROBLEM STATEMENT:

How many horses are there a string with multiple 'neighs' in it;
Given a string (of horse sound 'neigh'),
determine the minimum number of horses possible.
'Nneigheigh' should return 2, 'neighneigh' returns 1.
*/

#include "neigh.cpp"
#include <gtest/gtest.h>
#include <iostream>

using namespace std;


class NeighTest : public ::testing::Test {
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


TEST_F(NeighTest, Single) { 
    string sound = "neigh";
    int n_horses = 1;
    ASSERT_EQ(n_horses, solution->min_horses(sound));
}

TEST_F(NeighTest, anotherSingle) { 
    string sound = "neighneigh";
    int n_horses = 1;
    ASSERT_EQ(n_horses, solution->min_horses(sound));
}

TEST_F(NeighTest, Double) { 
    string sound = "nneigheigh";
    int n_horses = 2;
    ASSERT_EQ(n_horses, solution->min_horses(sound));
}

TEST_F(NeighTest, Triple) { 
    string sound = "nneingheighigh";
    int n_horses = 3;
    ASSERT_EQ(n_horses, solution->min_horses(sound));
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}