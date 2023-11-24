from unittest import TestCase, TestResult, TestLoader, TextTestRunner
from unique_paths_without_obstacles import Solution
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


class TestUniquePathsWithoutObstacles(TestCase):
    def setUp(self):
        # This method is called before each test
        self.solution = Solution()

    def test1_Grid1(self):
        m = 3
        n = 7
        expected = 28
        result = self.solution.unique_paths(m, n)

        self.assertEqual(result, expected)

    def test2_Grid2(self):
        m = 3
        n = 2
        expected = 3
        result = self.solution.unique_paths(m, n)

        self.assertEqual(result, expected)

    def tearDown(self):
        del self.solution  # Ensure the reference is deleted.


if __name__ == '__main__':
    suite = TestLoader().loadTestsFromTestCase(TestUniquePathsWithoutObstacles)
    result = CustomTestResult()
    runner = TextTestRunner(verbosity=2)
    # runner.run(suite)
    suite.run(result)
    result.printTestTimes()
