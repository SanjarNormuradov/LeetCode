from unittest import TestCase, TestResult, TestLoader
from flood_fill import Solution
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


class TestFloodFill(TestCase):
    def setUp(self):
        # This method is called before each test
        self.solution = Solution()

    def test1_SimpleCase(self):
        image = np.array([[1, 1, 1], [1, 1, 0], [1, 0, 1]])
        sr, sc, new_color = 1, 1, 2
        expected = np.array([[2, 2, 2], [2, 2, 0], [2, 0, 1]])
        result = self.solution.flood_fill(image, sr, sc, new_color)

        np.testing.assert_array_equal(result, expected)

    def test2_SameStartColor(self):
        image = np.array([[0, 1, 2], [3, 4, 5]])
        sr, sc, new_color = 0, 0, 0
        expected = np.array([[0, 1, 2], [3, 4, 5]])
        result = self.solution.flood_fill(image, sr, sc, new_color)

        np.testing.assert_array_equal(result, expected)

    def test3_ComplexCase(self):
        image = np.array([[6, 5, 1], [2, 1, 1], [1, 1, 3], [1, 0, 1]])
        sr, sc, new_color = 2, 1, 7
        expected = np.array([[6, 5, 7], [2, 7, 7], [7, 7, 3], [7, 0, 1]])
        result = self.solution.flood_fill(image, sr, sc, new_color)

        np.testing.assert_array_equal(result, expected)

    def tearDown(self):
        del self.solution  # Ensure the reference is deleted.


if __name__ == '__main__':
    suite = TestLoader().loadTestsFromTestCase(TestFloodFill)
    result = CustomTestResult()
    suite.run(result)
    result.printTestTimes()
