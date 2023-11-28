from unittest import TestCase, TestResult, TestLoader, TextTestRunner
from matrix01 import Solution
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


class TestMatrix01(TestCase):
    def setUp(self):
        # This method is called before each test
        self.solution = Solution()

    def test1_Matrix1(self):
        mat = np.array([[0, 0, 0], [0, 1, 0], [0, 0, 0]])
        expected = np.array([[0, 0, 0], [0, 1, 0], [0, 0, 0]])
        result = self.solution.update_matrix(mat)

        np.testing.assert_array_equal(result, expected)

    def test2_Matrix2(self):
        mat = np.array([[0, 0, 0], [0, 1, 0], [1, 1, 1]])
        expected = np.array([[0, 0, 0], [0, 1, 0], [1, 2, 1]])
        result = self.solution.update_matrix(mat)

        np.testing.assert_array_equal(result, expected)

    def tearDown(self):
        del self.solution  # Ensure the reference is deleted.


if __name__ == '__main__':
    suite = TestLoader().loadTestsFromTestCase(TestMatrix01)
    result = CustomTestResult()
    runner = TextTestRunner(verbosity=2)
    # runner.run(suite)
    suite.run(result)
    result.printTestTimes()
