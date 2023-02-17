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
    
    pair<int, int> solve(TreeNode *cur, int &ans) {
        if (cur == nullptr) return {INT_MAX, INT_MIN};
        int mn = cur->val, mx = cur->val;
        if (cur->left) {
            auto lft = solve(cur->left, ans);
            ans = min(ans, cur->val - lft.second);
            mn = lft.first;
        }
        if (cur->right) {
            auto rgt = solve(cur->right, ans);
            ans = min(ans, rgt.first - cur->val);
            mx = rgt.second;
        }
        return {mn, mx};
    }
    
    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX;
        solve(root, ans);
        return ans;
    }
};