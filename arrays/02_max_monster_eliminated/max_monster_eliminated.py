from typing import List


class Solution:
    def max_monster_eliminated(self, dist: List[int], speed: List[int]) -> int:
        if not self._check_constraints(dist, speed):
            raise ValueError("Constraints violated")

        n = len(dist)
        # Calculate time to reach the city for each monster
        time_to_city = [dist[i] / speed[i] for i in range(n)]
        time_to_city.sort()

        monsters_eliminated = 0
        for i in range(n):
            if time_to_city[i] <= i:
                return monsters_eliminated

            monsters_eliminated += 1

        return n

    def _check_constraints(self, dist: List[int], speed: List[int]) -> bool:
        n = len(dist)
        m = len(speed)
        if n != m:
            return False

        if n < 1 or n > 10**5:
            return False

        for i in range(n):
            if dist[i] < 1 or dist[i] > 10**5:
                return False
            if speed[i] < 1 or speed[i] > 10**5:
                return False

        return True
