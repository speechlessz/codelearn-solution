/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int,bool> mp, mq;
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p->val, q->val);
        TreeNode* res = root;
        for (;;) {
            if (res->left && contain(res->left)) res = res->left;
            else if (res->right && contain(res->right)) res = res->right;
            else break;
        }
        return res;
    }
    
    bool contain(TreeNode *r) {
        return mp[r->val] && mq[r->val];
    }
    
    void dfs(TreeNode* r, int p, int q) {
        if (r == NULL) return;
        mp[r->val] = r->val == p;
        mq[r->val] = r->val == q;
        
        if (r->left) {
            dfs(r->left, p, q);
            mp[r->val] = mp[r->val] || mp[r->left->val];
            mq[r->val] = mq[r->val] || mq[r->left->val];
        }
        
        if (r->right) {
            dfs(r->right, p, q);
            mp[r->val] = mp[r->val] || mp[r->right->val];
            mq[r->val] = mq[r->val] || mq[r->right->val];
        }
    }
};