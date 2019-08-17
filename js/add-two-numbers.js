/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    let carry = 0
    let res = new ListNode(0)
    let walker = res
    for (;;) {
        if (!l1 && l2) carry += l2.val, l2 = l2.next
        else if (!l2 && l1) carry += l1.val, l1 = l1.next
        else if (l1 && l2) {
            carry += l1.val + l2.val
            l1 = l1.next; l2 = l2.next;
        }
        walker.val = Math.floor(carry % 10)
        carry = Math.floor(carry / 10)
        // End of sum
        if (!l1 && !l2 && carry == 0) break;
        // Still have digit(s) or carry
        walker.next = new ListNode(0)
        walker = walker.next
    }
    return res
};