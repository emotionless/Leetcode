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
    
    pair<int, int> getMinMax(TreeNode *cur, int &ans) {
        if (cur->left == nullptr && cur->right == nullptr) return {cur->val, cur->val};
        int mn = cur->val, mx = cur->val;
        if (cur->left != nullptr) {
            auto left = getMinMax(cur->left, ans);
            ans = max(ans, abs(left.second - cur->val));
            ans = max(ans, abs(left.first - cur->val));
            mn = min(mn, left.first);
            mx = max(mx, left.second);
            
        }
        if (cur->right != nullptr) {
            auto right = getMinMax(cur->right, ans);
            mn = min(mn, right.first);
            mx = max(mx, right.second);
            ans = max(ans, abs(right.second - cur->val));
            ans = max(ans, abs(right.first - cur->val));
        }
        return {mn, mx};
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        getMinMax(root, ans);
        return ans;
    }
};