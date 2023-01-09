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
    
    void solve(TreeNode *cur, vector<int> &ans) {
        if (cur == nullptr) return;
        ans.push_back(cur->val);
        solve(cur->left, ans);
        solve(cur->right, ans);
        
        return;
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root, ans);
        
        return ans;
    }
};