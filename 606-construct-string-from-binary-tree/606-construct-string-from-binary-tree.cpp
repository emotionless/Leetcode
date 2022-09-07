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
    
    string solve(TreeNode *cur) {
        if (cur == nullptr) return "";
        if (cur->left == nullptr && cur->right == nullptr) return to_string(cur->val);
        return to_string(cur->val) + "(" + solve(cur->left) + ")" + (cur->right? ("(" + solve(cur->right) + ")") : "");
    }
    
    string tree2str(TreeNode* root) {
        return solve(root);
    }
};