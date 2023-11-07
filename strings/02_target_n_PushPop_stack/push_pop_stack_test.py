from unittest import TestCase, main
from target_n_PushPop_stack import Solution


class TestBuildArray(TestCase):
    def setUp(self):
        # This method is called before each test
        self.solution = Solution()

    def test_build_array_Push(self):
        self.assertEqual(self.solution.buildArray([1], 3), ["Push"])

    def test_build_array_PushPush(self):
        self.assertEqual(self.solution.buildArray([1, 2], 3), ["Push", "Push"])

    def test_build_array_PushPushPopPush(self):
        self.assertEqual(self.solution.buildArray([1, 3], 3), ["Push", "Push", "Pop", "Push"])

    def test_build_array_PushPopPush(self):
        self.assertEqual(self.solution.buildArray([2], 3), ["Push", "Pop", "Push"])

    def tearDown(self):
        del self.solution  # Ensure the reference is deleted.


if __name__ == '__main__':
    main()
