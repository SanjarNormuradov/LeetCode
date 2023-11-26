from unittest import TestCase, TestResult, TestLoader, TextTestRunner
from valid_word_abbreviation import Solution
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
class TestValidWordAbbreviation(TestCase):
    def setUp(self):
        # This method is called before each test
        self.solution = Solution()

    def test1_i12iz4n(self):
        word = "internationalization"
        abbr = "i12iz4n"
        expected = True
        result = self.solution.valid_word_abbreviation(word, abbr)

        self.assertEqual(result, expected)

    def test2_a2e(self):
        word = "apple"
        abbr = "a2e"
        expected = False
        result = self.solution.valid_word_abbreviation(word, abbr)

        self.assertEqual(result, expected)

    def test3_a(self):
        word = "a"
        abbr = "2"
        expected = False
        result = self.solution.valid_word_abbreviation(word, abbr)

        self.assertEqual(result, expected)

    def test4_s10n(self):
        word = "substitution"
        abbr = "s10n"
        expected = True
        result = self.solution.valid_word_abbreviation(word, abbr)

        self.assertEqual(result, expected)

    def test5_sub4u4(self):
        word = "substitution"
        abbr = "sub4u4"
        expected = True
        result = self.solution.valid_word_abbreviation(word, abbr)

        self.assertEqual(result, expected)

    def test6_12(self):
        word = "substitution"
        abbr = "12"
        expected = True
        result = self.solution.valid_word_abbreviation(word, abbr)

        self.assertEqual(result, expected)

    def test8_substitution(self):
        word = "substitution"
        abbr = "substitution"
        expected = True
        result = self.solution.valid_word_abbreviation(word, abbr)

        self.assertEqual(result, expected)

    def test9_s55n(self):
        word = "substitution"
        abbr = "s55n"
        expected = False
        result = self.solution.valid_word_abbreviation(word, abbr)

        self.assertEqual(result, expected)

    def test10_s010n(self):
        word = "substitution"
        abbr = "s010n"
        expected = False
        result = self.solution.valid_word_abbreviation(word, abbr)

        self.assertEqual(result, expected)

    def test11_s0ubstitution(self):
        word = "substitution"
        abbr = "s0ubstitution"
        expected = False
        result = self.solution.valid_word_abbreviation(word, abbr)

        self.assertEqual(result, expected)

    def test12_hi1(self):
        word = "hi"
        abbr = "hi1"
        expected = False
        result = self.solution.valid_word_abbreviation(word, abbr)

        self.assertEqual(result, expected)

    def test13_1(self):
        word = "hi"
        abbr = "1"
        expected = False
        result = self.solution.valid_word_abbreviation(word, abbr)

        self.assertEqual(result, expected)

    def tearDown(self):
        del self.solution  # Ensure the reference is deleted.


if __name__ == '__main__':
    suite = TestLoader().loadTestsFromTestCase(TestValidWordAbbreviation)
    result = CustomTestResult()
    runner = TextTestRunner(verbosity=2)
    # runner.run(suite)
    suite.run(result)
    result.printTestTimes()
