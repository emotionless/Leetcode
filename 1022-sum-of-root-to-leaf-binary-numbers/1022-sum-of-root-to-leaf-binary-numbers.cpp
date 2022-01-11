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
    
    int sumToLeaf(TreeNode *cur, int num) {
        if (cur -> left == nullptr && cur->right == nullptr) {
            return num * 2 + cur->val;
        }
        int ret = 0;
        if (cur->left)
            ret += sumToLeaf(cur->left, num * 2 + cur->val);
        if (cur->right)
            ret += sumToLeaf(cur->right, num * 2 + cur->val);
        return ret;
    }
    
    int sumRootToLeaf(TreeNode* root) {
        return sumToLeaf(root, 0);
    }
};