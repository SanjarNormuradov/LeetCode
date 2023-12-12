from unittest import TestCase, TestResult, TestLoader, TextTestRunner
from palindrome_permutationII import Solution
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


@time_tests
class TestPalindromePermutationII(TestCase):
    def setUp(self):
        # This method is called before each test
        self.solution = Solution()

    def test1_aabb(self):
        s = "aabb"
        expected = ["abba", "baab"]
        result = self.solution.generate_palindromes(s)
        expected.sort()
        result.sort()
        self.assertListEqual(result, expected)

    def test2_aabbc(self):
        s = "aabbc"
        expected = ["abcba", "bacab"]
        result = self.solution.generate_palindromes(s)
        expected.sort()
        result.sort()
        self.assertListEqual(result, expected)

    def test3_abc(self):
        s = "abc"
        expected = []
        result = self.solution.generate_palindromes(s)
        expected.sort()
        result.sort()
        self.assertListEqual(result, expected)

    def tearDown(self):
        del self.solution  # Ensure the reference is deleted.


if __name__ == '__main__':
    suite = TestLoader().loadTestsFromTestCase(TestPalindromePermutationII)
    result = CustomTestResult()
    runner = TextTestRunner(verbosity=2)
    # runner.run(suite)
    suite.run(result)
    result.printTestTimes()
