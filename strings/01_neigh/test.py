'''
PROBLEM STATEMENT:

How many horses are there a string with multiple 'neighs' in it;
Given a string (of horse sound 'neigh'),
determine the minimum number of horses possible.
'Nneigheigh' should return 2, 'neighneigh' returns 1.
'''

from unittest import TestCase, main
from neigh import Solution


class TestMinHorses(TestCase):
    def setUp(self):
        # This method is called before each test
        self.solution = Solution()

    def test_min_horse(self):
        self.assertEqual(self.solution.min_horses("neigh"), 1)

    def test_min_horses_another_single(self):
        self.assertEqual(self.solution.min_horses('neighneigh'), 1)

    def test_min_horses_double(self):
        self.assertEqual(self.solution.min_horses('nneigheigh'), 2)

    def test_min_horses_triple(self):
        self.assertEqual(self.solution.min_horses('nneingheighigh'), 3)

    def tearDown(self):
        del self.solution  # Ensure the reference is deleted.


if __name__ == '__main__':
    main()
