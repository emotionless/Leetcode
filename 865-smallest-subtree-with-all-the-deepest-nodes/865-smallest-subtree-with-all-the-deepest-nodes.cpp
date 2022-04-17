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
    
    int dfs(TreeNode *cur) {
        if (cur == nullptr) return 0;
        return 1 + max(dfs(cur->left), dfs(cur->right));
    }
    
    bool solve(TreeNode *cur, int l) {
        if (cur == nullptr) return false;
        if (l == 1) {
            ans = cur;
            return true;
        }
        bool lft = solve(cur->left, l - 1);
        bool rgt = solve(cur->right, l - 1);
        if (lft && rgt) {
            ans = cur;
        }
        return lft || rgt;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int len = dfs(root);
        solve(root, len);
        
        return ans;
    }
private:
    TreeNode *ans = nullptr;
};