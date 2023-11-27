#include <iostream>
#include <stdexcept>
#include <sstream>

using namespace std;


struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (!checkConstraints(l1, l2)) {
            throw std::runtime_error("Constraints violated");
        }
        ListNode *sum = new ListNode();
        sumDigits(l1, l2, sum, 0);
        return sum;
    }

private:
    void sumDigits(ListNode *l1, ListNode *l2, ListNode *output, int carry) {
        if (l1 == nullptr && l2 == nullptr && carry == 0) return;

        int sum = carry;
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }
        output->val = sum % 10;
        carry = sum / 10;
        if (l1 != nullptr || l2 != nullptr || carry != 0) {
            output->next = new ListNode();
            sumDigits(l1, l2, output->next, carry);
        }
    }
    // Helper function to check the constraints
    bool checkConstraints(ListNode *l1, ListNode *l2) {
        ListNode *temp = l1;
        int cnt = 0;
        while (temp) {
            cnt++;
            if (temp->val < 0 || temp->val > 9) {
                return false;
            }
            temp = temp->next;
        }
        if (cnt < 1 || cnt > 100) {
            return false;
        }
        cnt = 0;
        temp = l2;
        while (temp) {
            cnt++;
            if (temp->val < 0 || temp->val > 9) {
                return false;
            }
            temp = temp->next;
        }
        if (cnt < 1 || cnt > 100) {
            return false;
        }

        return true;
    }
};

