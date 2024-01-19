import numpy as np


class Solution:
    def flood_fill_util(self, image: np.ndarray,
                        sr: int, sc: int,
                        new_color: int, old_color: int) -> None:
        if (sr < 0 or sr >= image.shape[0]) or (sc < 0 or sc >= image.shape[1]) or (image[sr, sc] != old_color or image[sr, sc] == new_color):
            return

        image[sr, sc] = new_color

        self.flood_fill_util(image, sr + 1, sc, new_color, old_color)
        self.flood_fill_util(image, sr - 1, sc, new_color, old_color)
        self.flood_fill_util(image, sr, sc + 1, new_color, old_color)
        self.flood_fill_util(image, sr, sc - 1, new_color, old_color)

    def flood_fill(self, image: np.ndarray,
                   sr: int, sc: int,
                   new_color: int) -> np.ndarray:
        if not self._check_constraints(image, sr, sc, new_color):
            raise ValueError('Constraints violated')

        old_color = image[sr, sc]
        self.flood_fill_util(image, sr, sc, new_color, old_color)

        return image

    def _check_constraints(self, image: np.ndarray,
                           sr: int, sc: int,
                           new_color: int) -> bool:
        m = image.shape[0]
        if m == 0 or m > 50:
            return False

        for row in image:
            n = row.shape[0]
            if n == 0 or n > 50:
                return False

            for color in row:
                if color < 0 or color >= 2**16:
                    return False

        if new_color < 0 or new_color >= 2**16:
            return False

        if (sr < 0 or sr >= m) or (sc < 0 or sc >= n):
            return False

        return True
