from unittest import TestCase, TestResult, TestLoader
from count_increasing_path import Solution
from time import time
import numpy as np

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


class TestCountIncreasingPath(TestCase):
    def setUp(self):
        # This method is called before each test
        self.solution = Solution()

    def test1_Grid1(self):
        grid = np.array([[9, 9, 4], [6, 6, 8], [2, 1, 1]])
        expected = 23
        result = self.solution.count_paths(grid)

        self.assertEqual(result, expected)

    def test2_Grid2(self):
        grid = np.array([[3, 4, 5], [3, 2, 6], [2, 2, 1]])
        expected = 23
        result = self.solution.count_paths(grid)

        self.assertEqual(result, expected)

    def test3_Grid3(self):
        grid = np.array([[1]])
        expected = 1
        result = self.solution.count_paths(grid)

        self.assertEqual(result, expected)

    def test4_Grid4(self):
        grid = np.array([[1, 2]])
        expected = 3
        result = self.solution.count_paths(grid)

        self.assertEqual(result, expected)

    def test5_Grid5(self):
        grid = np.array([[1], [2]])
        expected = 3
        result = self.solution.count_paths(grid)

        self.assertEqual(result, expected)

    def test6_Grid6(self):
        grid = np.array([[1, 1], [3, 4]])
        expected = 8
        result = self.solution.count_paths(grid)

        self.assertEqual(result, expected)

    def tearDown(self):
        del self.solution  # Ensure the reference is deleted.


if __name__ == '__main__':
    suite = TestLoader().loadTestsFromTestCase(TestCountIncreasingPath)
    result = CustomTestResult()
    suite.run(result)
    result.printTestTimes()
