/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var inorderTraversal = function(root) {
    res = []
    cur = root
    st = []
    while (cur != null || st.length > 0) {
        while (cur != null) {
            st.push(cur)
            cur = cur.left
        }
        cur = st[st.length-1]
        st = st.slice(0, st.length-1)
        res.push(cur.val)
        cur = cur.right
    }
    return res
};