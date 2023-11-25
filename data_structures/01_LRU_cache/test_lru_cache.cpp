#include "lru_cache.cpp"
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


class TestLRUCache : public ::testing::Test {
protected:
    LRUCache* cache; // Each test will have its own pointer to LRUCache instance

    void SetUp() override {
        // Code here will be called immediately after the constructor 
        // (right before each test).
        cache = new LRUCache();
    }

    void TearDown() override {
        // Code here will be called immediately after each test 
        // (right before the destructor).
        delete cache;
    }
};


TEST_F(TestLRUCache, test1_Cache1) {
    cache->setCapacity(2);
    cache->put(1, 1);
    cache->put(2, 2);
    int result = cache->get(1);
    int expected = 1;
    ASSERT_EQ(expected, result);
    
    cache->put(3, 3);
    result = cache->get(2);
    expected = -1;
    ASSERT_EQ(expected, result);

    cache->put(4, 4);
    result = cache->get(1);
    expected = -1;
    ASSERT_EQ(expected, result);

    result = cache->get(3);
    expected = 3;
    ASSERT_EQ(expected, result);

    result = cache->get(4);
    expected = 4;
    ASSERT_EQ(expected, result);
}

TEST_F(TestLRUCache, test2_Cache2) {
    cache->setCapacity(2);
    cache->put(1, 1);
    cache->put(2, 2);
    cache->put(2, 3);
    int result = cache->get(2);
    int expected = 3;
    ASSERT_EQ(expected, result);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    // Adds the custom listener to the end. Google Test takes the ownership.
    ::testing::TestEventListeners& listeners = ::testing::UnitTest::GetInstance()->listeners();
    listeners.Append(new CustomTestListener);

    return RUN_ALL_TESTS();
}