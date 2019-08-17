/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	carry := 0
	res := &ListNode{0, nil}
	walker := res
	for {
		if l1 == nil && l2 != nil {
			carry += l2.Val
			l2 = l2.Next
		} else if l2 == nil && l1 != nil {
			carry += l1.Val
			l1 = l1.Next
		} else if l1 != nil && l2 != nil {
			carry += l1.Val + l2.Val
			l1 = l1.Next
			l2 = l2.Next
		}
		walker.Val = carry % 10
		carry /= 10
		// End of sum
		if l1 == nil && l2 == nil && carry == 0 {
			break
		}
		// Still have digit(s) or carry
		walker.Next = &ListNode{0, nil}
		walker = walker.Next
	}
	return res
}