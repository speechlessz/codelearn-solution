/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func oddEvenList(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}

	odd := head
	even := head.Next

	var pl *ListNode
	l := odd
	r := even
	isOdd := true
	for r != nil {
		l.Next = r.Next
		pl = l
		l = r
		r = r.Next
		isOdd = !isOdd
	}

	if isOdd {
		l.Next = even
	} else {
		pl.Next = even
	}

	return head
}