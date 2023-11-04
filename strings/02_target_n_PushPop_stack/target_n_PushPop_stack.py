from typing import List


class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        assert n >= 1 and n <= 100
        assert len(target) >= 1 and len(target) <= 100
        assert all(target[i] <= target[i + 1] for i in range(len(target) - 1))

        stack: List[str] = []
        target_cnt = 0

        for stream_num in range(1, n + 1):
            stack.append("Push")
            if stream_num == target[target_cnt]:
                target_cnt += 1
                if target_cnt == len(target):
                    return stack
            else:
                stack.append("Pop")

        return stack
