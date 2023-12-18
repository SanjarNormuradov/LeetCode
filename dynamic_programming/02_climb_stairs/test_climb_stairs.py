from unittest import TestCase, TestResult, TestLoader, TextTestRunner
from climb_stairs import Solution
from time import time

from functools import wraps


class CustomTestResult(TestResult):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.test_times = []

    def startTest(self, test):
        self._start_time = time()
        super().startTest(test)

    def stopTest(self, test):
        elapsed_time = time() - self._start_time
        self.test_times.append((test.id().split('.')[-1], elapsed_time))
        super().stopTest(test)

    def printTestTimes(self):
        name_width = 60
        print("\nTest Time Results:\n")
        for name, elapsed_time in self.test_times:
            print(f"{name:<{name_width}}time: {elapsed_time:.2e} s")
        print()


def time_tests(cls):
    """Class decorator for adding time measurements to all test methods of a TestCase."""
    for attr in dir(cls):
        if attr.startswith('test'):
            old_method = getattr(cls, attr)

            @wraps(old_method)
            def new_method(self, *args, method=old_method, **kwargs):
                method(self, *args, **kwargs)
            setattr(cls, attr, new_method)
    return cls


class TestClimbStairs(TestCase):
    def setUp(self):
        # This method is called before each test
        self.solution = Solution()

    def test1_n2(self):
        n = 2
        expected = 2
        result = self.solution.climb_stairs(n)

        self.assertEqual(result, expected)

    def test2_n3(self):
        n = 3
        expected = 3
        result = self.solution.climb_stairs(n)

        self.assertEqual(result, expected)

    def test3_n6(self):
        n = 6
        expected = 13
        result = self.solution.climb_stairs(n)

        self.assertEqual(result, expected)

    def tearDown(self):
        del self.solution  # Ensure the reference is deleted.


if __name__ == '__main__':
    suite = TestLoader().loadTestsFromTestCase(TestClimbStairs)
    result = CustomTestResult()
    runner = TextTestRunner(verbosity=2)
    # runner.run(suite)
    suite.run(result)
    result.printTestTimes()
