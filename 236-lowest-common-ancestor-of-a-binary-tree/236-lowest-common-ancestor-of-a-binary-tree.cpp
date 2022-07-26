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
    
    bool solve(TreeNode *cur, TreeNode* p, TreeNode* q, TreeNode*  &ans) {
        if (cur == nullptr) return false;
        bool lft = solve(cur->left, p, q, ans);
        bool rgt = solve(cur->right, p, q, ans);
        if (lft == true && rgt == true) {
            ans = cur;
        } else if (lft == true && (cur-> val == p->val || cur->val == q->val)) {
            ans = cur;
        } else if (rgt == true && (cur-> val == p->val || cur->val == q->val)) {
            ans = cur;
        }
        
        return lft || rgt || cur->val == p->val || cur->val == q->val;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *ans = NULL;
        solve(root, p, q, ans);
        return ans;
    }
};