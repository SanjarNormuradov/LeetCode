from unittest import TestCase, main
from flood_fill import Solution
import numpy as np


class TestFloodFill(TestCase):
    def setUp(self):
        # This method is called before each test
        self.solution = Solution()

    def test_flood_fill_simple_case(self):
        image = np.array([[1, 1, 1], [1, 1, 0], [1, 0, 1]])
        sr, sc, new_color = 1, 1, 2
        expected = np.array([[2, 2, 2], [2, 2, 0], [2, 0, 1]])
        result = self.solution.flood_fill(image, sr, sc, new_color)
        np.testing.assert_array_equal(result, expected)

    def test_flood_fill_same_start_color(self):
        image = np.array([[0, 1, 2], [3, 4, 5]])
        sr, sc, new_color = 0, 0, 0
        expected = np.array([[0, 1, 2], [3, 4, 5]])
        result = self.solution.flood_fill(image, sr, sc, new_color)
        np.testing.assert_array_equal(result, expected)

    def test_flood_fill_complex_case(self):
        image = np.array([[6, 5, 1], [2, 1, 1], [1, 1, 3], [1, 0, 1]])
        sr, sc, new_color = 2, 1, 7
        expected = np.array([[6, 5, 7], [2, 7, 7], [7, 7, 3], [7, 0, 1]])
        result = self.solution.flood_fill(image, sr, sc, new_color)
        np.testing.assert_array_equal(result, expected)

    def tearDown(self):
        del self.solution  # Ensure the reference is deleted.


if __name__ == '__main__':
    main()
