# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        carry = 0
        res = ListNode(0)
        walker = res
        while 1:
            if not l1 and l2:
                carry += l2.val
                l2 = l2.next
            elif not l2 and l1:
                carry += l1.val
                l1 = l1.next
            elif None not in [l1, l2]:
                carry += l1.val + l2.val
                l1 = l1.next
                l2 = l2.next
            walker.val = carry % 10
            carry //= 10
            if not l1 and not l2 and carry == 0: break
            walker.next = ListNode(0)
            walker = walker.next
        return res
