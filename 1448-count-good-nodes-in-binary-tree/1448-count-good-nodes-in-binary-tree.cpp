/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int getGoodNodes(TreeNode *cur, int mx) {
        if (cur == nullptr) return 0;
        int ret = 0;
        if (mx <= cur -> val) ret = 1;
        ret += getGoodNodes(cur->left, max(mx, cur->val));
        ret += getGoodNodes(cur->right, max(mx, cur->val));
        
        return ret;
    }
    
    int goodNodes(TreeNode* root) {
        return getGoodNodes(root, INT_MIN);
    }
};