/**
 * Definition for TreeNode.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var mp, mq map[int]bool

func contains(r *TreeNode) bool {
	return mp[r.Val] && mq[r.Val]
}

func dfs(r *TreeNode, p, q int) {
	if r == nil {
		return
	}

	mp[r.Val] = r.Val == p
	mq[r.Val] = r.Val == q

	if r.Left != nil {
		dfs(r.Left, p, q)
		mp[r.Val] = mp[r.Val] || mp[r.Left.Val]
		mq[r.Val] = mq[r.Val] || mq[r.Left.Val]
	}

	if r.Right != nil {
		dfs(r.Right, p, q)
		mp[r.Val] = mp[r.Val] || mp[r.Right.Val]
		mq[r.Val] = mq[r.Val] || mq[r.Right.Val]
	}
}

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	mp = map[int]bool{}
	mq = map[int]bool{}

	dfs(root, p.Val, q.Val)
	res := root
	for {
		if res.Left != nil && contains(res.Left) {
			res = res.Left
		} else if res.Right != nil && contains(res.Right) {
			res = res.Right
		} else {
			break
		}
	}
	return res
}