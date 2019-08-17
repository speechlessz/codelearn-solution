/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *res = new ListNode(0);
        ListNode *walker = res;
        for (;;) {
            if (l1 == NULL && l2 != NULL) carry += l2->val, l2 = l2->next;
            else if (l2 == NULL && l1 != NULL) carry += l1->val, l1 = l1->next;
            else if (l1 != NULL && l2 != NULL) {
                carry += l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }
            walker->val = carry % 10;
            carry /= 10;
            // End of sum
            if (l1 == NULL && l2 == NULL && carry == 0) break;
            // Still have digit(s) or carry
            walker->next = new ListNode(0);
            walker = walker->next;
        }
        
        return res;
    }
};