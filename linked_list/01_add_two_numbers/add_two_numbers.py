class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def add_two_numbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not self._check_constraints(l1, l2):
            raise ValueError("Constraints violated")
        output = ListNode()
        self.sum_digits(l1, l2, output, 0)

        return output

    def sum_digits(self, l1: ListNode, l2: ListNode, output: ListNode, carry: int) -> None:
        if l1 is None and l2 is None and carry == 0:
            return

        sum = carry
        if l1 is not None:
            sum += l1.val
            l1 = l1.next
        if l2 is not None:
            sum += l2.val
            l2 = l2.next

        output.val = sum % 10
        carry = sum // 10
        if l1 is not None or l2 is not None or carry != 0:
            output.next = ListNode()
            self.sum_digits(l1, l2, output.next, carry)

#   Helper function to check the constraints
    def _check_constraints(self, l1: ListNode, l2: ListNode) -> bool:
        temp = l1
        cnt = 0
        while temp:
            cnt += 1
            if temp.val < 0 or temp.val > 9:
                return False
            temp = temp.next
        if cnt < 1 or cnt > 100:
            return False

        cnt = 0
        temp = l2
        while temp:
            cnt += 1
            if temp.val < 0 or temp.val > 9:
                return False
            temp = temp.next
        if cnt < 1 or cnt > 100:
            return False

        return True
