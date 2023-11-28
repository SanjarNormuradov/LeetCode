import numpy as np
from collections import deque
from typing import Deque, Tuple


class Solution:
    def update_matrix(self, mat: np.ndarray) -> np.ndarray:
        if not self._check_constraints(mat):
            raise ValueError('Constraints violated')

        row, col = mat.shape
        dist = np.ones_like(mat) * np.iinfo(np.int32).max
        q: Deque[Tuple[int, int]] = deque()
        # Init as a root for BFS every cell that is 0
        for i in range(row):
            for j in range(col):
                if (mat[i, j] == 0):
                    dist[i, j] = 0
                    q.append((i, j))
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        while q:
            id = q.popleft()
            for dir in dirs:
                x, y = id[0] + dir[0], id[1] + dir[1]
                if x >= 0 and x < row and y >= 0 and y < col:
                    if dist[x, y] > dist[id] + 1:
                        dist[x, y] = dist[id] + 1
                        q.append((x, y))

        return dist

    def _check_constraints(self, mat: np.ndarray) -> bool:
        m = mat.shape[0]
        if m == 0 or m > 10**4:
            return False
        zero_cnt = 0
        for row in mat:
            if row.shape[0] == 0 or row.shape[0] > 10**4:
                return False
            for num in row:
                if not (num == 0 or num == 1):
                    return False
                if num == 0:
                    zero_cnt += 1

        if not zero_cnt:
            return False

        return True
