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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return NULL;
        
        ListNode *odd = head, *even = head->next, *l = odd, *r = even, *pl;
        
        bool isOdd = true;
        while (r) {
            l->next = r->next;
            pl = l;
            l = r;
            r = r->next;
            isOdd = !isOdd;
        }
        
        if (isOdd) l->next = even;
        else pl->next = even;
        
        return head;
    }
};