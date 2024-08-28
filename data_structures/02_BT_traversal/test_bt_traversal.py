from unittest import TestCase, TestResult, TestLoader, TextTestRunner
from bt_traversal import Solution, TreeNode
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


class TestBTTraversal(TestCase):
    def setUp(self):
        # This method is called before each test
        self.solution = Solution()

    def test1_InOrder1(self):
        root = [1, None, 2, 3]
        rootNode = self.solution.insertLevelOrder(root)
        result = self.solution.inorderTraversal(rootNode)
        expected = [1, 3, 2]
        self.assertListEqual(result, expected)

    def test2_InOrder2(self):
        root = []
        rootNode = self.solution.insertLevelOrder(root)
        result = self.solution.inorderTraversal(rootNode)
        expected = []
        self.assertListEqual(result, expected)

    def test3_InOrder3(self):
        root = [1]
        rootNode = self.solution.insertLevelOrder(root)
        result = self.solution.inorderTraversal(rootNode)
        expected = [1]
        self.assertListEqual(result, expected)

    def test4_InOrder4(self):
        root = [1, 5, 2, 6, None, 3, 4]
        rootNode = self.solution.insertLevelOrder(root)
        result = self.solution.inorderTraversal(rootNode)
        expected = [6, 5, 1, 3, 2, 4]
        self.assertListEqual(result, expected)

    def test5_PreOrder1(self):
        root = [1, 5, 2, 6, None, 3, 4]
        rootNode = self.solution.insertLevelOrder(root)
        result = self.solution.preorderTraversal(rootNode)
        expected = [1, 5, 6, 2, 3, 4]
        self.assertListEqual(result, expected)

    def test6_PostOrder1(self):
        root = [1, 5, 2, 6, None, 3, 4]
        rootNode = self.solution.insertLevelOrder(root)
        result = self.solution.postorderTraversal(rootNode)
        expected = [6, 5, 3, 4, 2, 1]
        self.assertListEqual(result, expected)

    def test7_LevelOrder1(self):
        root = [1, 5, 2, 6, None, 3, 4]
        rootNode = self.solution.insertLevelOrder(root)
        result = self.solution.levelorderTraversal(rootNode)
        expected = [[1], [5, 2], [6, 3, 4]]
        self.assertListEqual(result, expected)

    def test8_LevelOrder2(self):
        root = [0, 2, 4, 1, None, 3, -1, 5, 1, None, 6, None, 8]
        rootNode = self.solution.insertLevelOrder(root)
        result = self.solution.levelorderTraversal(rootNode)
        expected = [[0], [2, 4], [1, 3, -1], [5, 1, 6, 8]]
        self.assertListEqual(result, expected)

    def tearDown(self):
        del self.solution  # Ensure the reference is deleted.


if __name__ == '__main__':
    suite = TestLoader().loadTestsFromTestCase(TestBTTraversal)
    result = CustomTestResult()
    runner = TextTestRunner(verbosity=2)
    # runner.run(suite)
    suite.run(result)
    result.printTestTimes()
