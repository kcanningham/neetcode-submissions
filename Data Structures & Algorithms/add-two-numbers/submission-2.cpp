/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseLL(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* L1 = l1;
        ListNode* L2 = l2;
        ListNode* dummy = new ListNode(0);
        ListNode* L3 = dummy;
        int carry = 0;

        while(L1 || L2 || carry != 0) {
            int v1 = (L1) ? L1->val : 0;
            int v2 = (L2) ? L2->val : 0;

            int sum = v1 + v2 + carry;
            carry = sum / 10;
            sum = sum % 10;
            L3->next = new ListNode(sum);

            L3 = L3->next;
            L1 = (L1) ? L1->next : nullptr;
            L2 = (L2) ? L2->next : nullptr;
        }
        return dummy->next;
    }
};
