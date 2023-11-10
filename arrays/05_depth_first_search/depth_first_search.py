import numpy as np


class Solution:
    def _depth_first_search(self, i: int, j: int) -> int:
        if self.path[i, j] > 0:
            return self.path[i, j]

        steps = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        for dx, dy in steps:
            x, y = i + dx, j + dy
            if (0 <= x < self.m) and (0 <= y < self.n) and (self.mat[x, y] > self.mat[i, j]):
                self.path[i, j] = max(self.path[i, j], self._depth_first_search(x, y))

        self.path[i, j] += 1
        return self.path[i, j]

    def longest_increasing_path(self, matrix: np.ndarray) -> int:
        if not self._check_constraints(matrix):
            raise ValueError('Constraints violated')

        self.path = np.zeros_like(matrix, dtype=np.uint16)
        self.mat = matrix
        self.m, self.n = matrix.shape
        max_length = 1
        for i in range(self.m):
            for j in range(self.n):
                max_length = max(max_length, self._depth_first_search(i, j))

        return max_length

    def _check_constraints(self, mat: np.ndarray) -> bool:
        if mat.shape[0] == 0 or mat.shape[0] > 200:
            return False

        for row in mat:
            if row.shape[0] == 0 or row.shape[0] > 200:
                return False

            for num in row:
                if num < 0 or num > 2**32 - 1:
                    return False

        return True
