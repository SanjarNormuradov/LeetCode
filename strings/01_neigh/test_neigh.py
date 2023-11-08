'''
PROBLEM STATEMENT:

How many horses are there a string with multiple 'neighs' in it;
Given a string (of horse sound 'neigh'),
determine the minimum number of horses possible.
'Nneigheigh' should return 2, 'neighneigh' returns 1.
'''

from unittest import TestCase, TestResult, TestLoader
from neigh import Solution
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
class TestNeigh(TestCase):
    def setUp(self):
        # This method is called before each test
        self.solution = Solution()

    def test1_Single(self):
        sound = "neigh"
        expected = 1
        result = self.solution.min_horses(sound)

        self.assertEqual(expected, result)

    def test2_anotherSingle(self):
        sound = "neighneigh"
        expected = 1
        result = self.solution.min_horses(sound)

        self.assertEqual(expected, result)

    def test3_Double(self):
        sound = "nneigheigh"
        expected = 2
        result = self.solution.min_horses(sound)

        self.assertEqual(expected, result)

    def test4_Triple(self):
        sound = "nneingheighigh"
        expected = 3
        result = self.solution.min_horses(sound)

        self.assertEqual(expected, result)

    def tearDown(self):
        del self.solution  # Ensure the reference is deleted.


if __name__ == '__main__':
    suite = TestLoader().loadTestsFromTestCase(TestNeigh)
    result = CustomTestResult()
    suite.run(result)
    result.printTestTimes()
