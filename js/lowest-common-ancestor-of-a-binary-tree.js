/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */

const mp = {},
      mq = {}

const contains = (r) => mp[r.val] && mq[r.val]

const dfs = (r, p, q) => {
    if (!r) return;
    mp[r.val] = r.val == p
    mq[r.val] = r.val == q
    
    if (r.left) {
        dfs(r.left, p, q)
        mp[r.val] = mp[r.val] || mp[r.left.val]
        mq[r.val] = mq[r.val] || mq[r.left.val]
    }
    
    if (r.right) {
        dfs(r.right, p, q)
        mp[r.val] = mp[r.val] || mp[r.right.val]
        mq[r.val] = mq[r.val] || mq[r.right.val]
    }
}

var lowestCommonAncestor = function(root, p, q) {
    dfs(root, p.val, q.val)
    let res = root
    for (;;) {
        if (res.left && contains(res.left)) res = res.left
        else if (res.right && contains(res.right)) res = res.right
        else break
    }
    return res
};
