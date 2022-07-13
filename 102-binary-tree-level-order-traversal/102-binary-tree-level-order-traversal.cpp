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
    
    void traverse(TreeNode *cur, int lvl, vector<vector<int>> &ans) {
        if (cur == nullptr) {
            return;
        }
        if (ans.size() <= lvl) {
            ans.push_back({cur->val});
        } else {
            ans[lvl].push_back(cur->val);
        }
        traverse(cur->left, lvl + 1, ans);
        traverse(cur->right, lvl + 1, ans);
        
        return;
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        traverse(root, 0, ans);
        
        return ans;
    }
};