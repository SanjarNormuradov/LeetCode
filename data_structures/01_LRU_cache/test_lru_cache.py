from unittest import TestCase, TestResult, TestLoader, TextTestRunner
from lru_cache import LRUCache
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


class TestLRUCache(TestCase):
    def setUp(self):
        # This method is called before each test
        self.cache = LRUCache()

    def test1_Cache1(self):
        self.cache.capacity = 2
        self.cache.put(1, 1)
        self.cache.put(2, 2)
        result = self.cache.get(1)
        expected = 1
        self.assertEqual(result, expected)

        self.cache.put(3, 3)
        result = self.cache.get(2)
        expected = -1
        self.assertEqual(result, expected)

        self.cache.put(4, 4)
        result = self.cache.get(1)
        expected = -1
        self.assertEqual(result, expected)

        result = self.cache.get(3)
        expected = 3
        self.assertEqual(result, expected)

        result = self.cache.get(4)
        expected = 4
        self.assertEqual(result, expected)

    def test2_Cache2(self):
        self.cache.capacity = 2
        self.cache.put(1, 1)
        self.cache.put(2, 2)
        self.cache.put(2, 3)
        result = self.cache.get(2)
        expected = 3
        self.assertEqual(result, expected)

    def tearDown(self):
        del self.cache  # Ensure the reference is deleted.


if __name__ == '__main__':
    suite = TestLoader().loadTestsFromTestCase(TestLRUCache)
    result = CustomTestResult()
    runner = TextTestRunner(verbosity=2)
    # runner.run(suite)
    suite.run(result)
    result.printTestTimes()
