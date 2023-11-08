#include "flood_fill.cpp"
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


class TestFloodFill : public ::testing::Test {
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


TEST_F(TestFloodFill, test1_SimpleCase) { 
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1, sc = 1, newColor = 2;
    vector<vector<int>> expected = {{2, 2, 2}, {2, 2, 0}, {2, 0, 1}};
    vector<vector<int>> result = solution->floodFill(image, sr, sc, newColor);

    ASSERT_EQ(expected, result);
}

TEST_F(TestFloodFill, test2_SameStartColor) { 
    vector<vector<int>> image = {{0, 1, 2}, {3, 4, 5}};
    int sr = 0, sc = 0, newColor = 0;
    vector<vector<int>> expected = {{0, 1, 2}, {3, 4, 5}};
    vector<vector<int>> result = solution->floodFill(image, sr, sc, newColor);

    ASSERT_EQ(expected, result);
}

TEST_F(TestFloodFill, test3_ComplexCase) { 
    vector<vector<int>> image = {{6, 5, 1}, {2, 1, 1}, {1, 1, 3}, {1, 0, 1}};
    int sr = 2, sc = 1, newColor = 7;
    vector<vector<int>> expected = {{6, 5, 7}, {2, 7, 7}, {7, 7, 3}, {7, 0, 1}};
    vector<vector<int>> result = solution->floodFill(image, sr, sc, newColor);

    ASSERT_EQ(expected, result);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    // Adds the custom listener to the end. Google Test takes the ownership.
    ::testing::TestEventListeners& listeners = ::testing::UnitTest::GetInstance()->listeners();
    listeners.Append(new CustomTestListener);

    return RUN_ALL_TESTS();
}