from unittest import TestCase, TestResult, TestLoader, TextTestRunner
from add_two_numbers import Solution, ListNode
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
class TestAddTwoNumbers(TestCase):
    def setUp(self):
        # This method is called before each test
        self.solution = Solution()

    def test1_807(self):
        l1 = ListNode(2, ListNode(4, ListNode(3)))
        l2 = ListNode(5, ListNode(6, ListNode(4)))
        result = self.solution.add_two_numbers(l1, l2)
        expected = [7, 0, 8]
        for digit in expected:
            self.assertEqual(result.val, digit)
            result = result.next

    def test2_0(self):
        l1 = ListNode()
        l2 = ListNode()
        result = self.solution.add_two_numbers(l1, l2)
        expected = 0
        self.assertEqual(result.val, expected)

    def test3_10009998(self):
        l1 = ListNode(9, ListNode(9, ListNode(9, ListNode(9, ListNode(9, ListNode(9, ListNode(9)))))))
        l2 = ListNode(9, ListNode(9, ListNode(9, ListNode(9))))
        result = self.solution.add_two_numbers(l1, l2)
        expected = [8, 9, 9, 9, 0, 0, 0, 1]
        for digit in expected:
            self.assertEqual(result.val, digit)
            result = result.next

    def tearDown(self):
        del self.solution  # Ensure the reference is deleted.


if __name__ == '__main__':
    suite = TestLoader().loadTestsFromTestCase(TestAddTwoNumbers)
    result = CustomTestResult()
    runner = TextTestRunner(verbosity=2)
    # runner.run(suite)
    suite.run(result)
    result.printTestTimes()
