#include "valid_word_abbreviation.cpp"
#include <gtest/gtest.h>
#include <string>
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


class TestValidWordAbbreviation : public ::testing::Test {
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


TEST_F(TestValidWordAbbreviation, test1_i12iz4n) {
    string word = "internationalization";
    string abbr = "i12iz4n";
    bool expected = true;
    bool result = solution->validWordAbbreviation(word, abbr);

    ASSERT_EQ(expected, result);
}

TEST_F(TestValidWordAbbreviation, test2_a2e) { 
    string word = "apple";
    string abbr = "a2e";
    bool expected = false;
    bool result = solution->validWordAbbreviation(word, abbr);

    ASSERT_EQ(expected, result);
}

TEST_F(TestValidWordAbbreviation, test3_a) { 
    string word = "a";
    string abbr = "2";
    bool expected = false;
    bool result = solution->validWordAbbreviation(word, abbr);

    ASSERT_EQ(expected, result);
}

TEST_F(TestValidWordAbbreviation, test4_s10n) { 
    string word = "substitution";
    string abbr = "s10n";
    bool expected = true;
    bool result = solution->validWordAbbreviation(word, abbr);

    ASSERT_EQ(expected, result);
}

TEST_F(TestValidWordAbbreviation, test5_sub4u4) { 
    string word = "substitution";
    string abbr = "sub4u4";
    bool expected = true;
    bool result = solution->validWordAbbreviation(word, abbr);

    ASSERT_EQ(expected, result);
}

TEST_F(TestValidWordAbbreviation, test6_12) { 
    string word = "substitution";
    string abbr = "12";
    bool expected = true;
    bool result = solution->validWordAbbreviation(word, abbr);

    ASSERT_EQ(expected, result);
}

TEST_F(TestValidWordAbbreviation, test7_su3i1u2on) { 
    string word = "substitution";
    string abbr = "su3i1u2on";
    bool expected = true;
    bool result = solution->validWordAbbreviation(word, abbr);

    ASSERT_EQ(expected, result);
}

TEST_F(TestValidWordAbbreviation, test8_substitution) { 
    string word = "substitution";
    string abbr = "substitution";
    bool expected = true;
    bool result = solution->validWordAbbreviation(word, abbr);

    ASSERT_EQ(expected, result);
}

TEST_F(TestValidWordAbbreviation, test9_s55n) { 
    string word = "substitution";
    string abbr = "s55n";
    bool expected = false;
    bool result = solution->validWordAbbreviation(word, abbr);

    ASSERT_EQ(expected, result);
}

TEST_F(TestValidWordAbbreviation, test10_s010n) { 
    string word = "substitution";
    string abbr = "s010n";
    bool expected = false;
    bool result = solution->validWordAbbreviation(word, abbr);

    ASSERT_EQ(expected, result);
}

TEST_F(TestValidWordAbbreviation, test11_s0ubstitution) { 
    string word = "substitution";
    string abbr = "s0ubstitution";
    bool expected = false;
    bool result = solution->validWordAbbreviation(word, abbr);

    ASSERT_EQ(expected, result);
}

TEST_F(TestValidWordAbbreviation, test12_hi1) { 
    string word = "hi";
    string abbr = "hi1";
    bool expected = false;
    bool result = solution->validWordAbbreviation(word, abbr);

    ASSERT_EQ(expected, result);
}

TEST_F(TestValidWordAbbreviation, test13_1) { 
    string word = "hi";
    string abbr = "1";
    bool expected = false;
    bool result = solution->validWordAbbreviation(word, abbr);

    ASSERT_EQ(expected, result);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    // Adds the custom listener to the end. Google Test takes the ownership.
    ::testing::TestEventListeners& listeners = ::testing::UnitTest::GetInstance()->listeners();
    listeners.Append(new CustomTestListener);

    return RUN_ALL_TESTS();
}