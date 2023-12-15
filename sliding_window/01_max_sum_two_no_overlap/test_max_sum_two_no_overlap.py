from unittest import TestCase, TestResult, TestLoader, TextTestRunner
from max_sum_two_no_overlap import Solution
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


class TestMaxSumTwoNoOverlap(TestCase):
    def setUp(self):
        # This method is called before each test
        self.solution = Solution()

    def test1_Len12(self):
        nums = [0, 6, 5, 2, 2, 5, 1, 9, 4]
        first_len = 1
        second_len = 2
        expected = 20
        result = self.solution.max_sum_two_no_overlap(nums, first_len, second_len)

        self.assertEqual(result, expected)

    def test2_Len32(self):
        nums = [3, 8, 1, 3, 2, 1, 8, 9, 0]
        first_len = 3
        second_len = 2
        expected = 29
        result = self.solution.max_sum_two_no_overlap(nums, first_len, second_len)

        self.assertEqual(result, expected)

    def test3_Len43(self):
        nums = [2, 1, 5, 6, 0, 9, 5, 0, 3, 8]
        first_len = 4
        second_len = 3
        expected = 31
        result = self.solution.max_sum_two_no_overlap(nums, first_len, second_len)

        self.assertEqual(result, expected)

    def test4_Len53(self):
        nums = [4, 5, 14, 16, 16, 20, 7, 13, 8, 15]
        first_len = 5
        second_len = 2
        expected = 109
        result = self.solution.max_sum_two_no_overlap(nums, first_len, second_len)

        self.assertEqual(result, expected)

    def tearDown(self):
        del self.solution  # Ensure the reference is deleted.


if __name__ == '__main__':
    suite = TestLoader().loadTestsFromTestCase(TestMaxSumTwoNoOverlap)
    result = CustomTestResult()
    runner = TextTestRunner(verbosity=2)
    # runner.run(suite)
    suite.run(result)
    result.printTestTimes()
