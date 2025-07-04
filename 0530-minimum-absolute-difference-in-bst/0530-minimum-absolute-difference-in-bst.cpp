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
    pair<int, int> solve(TreeNode *cur) {
        if (cur->left == NULL && cur->right == NULL) {
            return pair(cur->val, cur->val);
        } else if (cur->left == NULL) {
            pair<int, int> p = solve(cur->right);
            ans = min(ans, abs(cur->val- p.first));
            return pair(cur->val, p.second);
        } else if (cur->right == NULL) {
            pair<int, int> p = solve(cur->left);
            ans = min(ans, abs(cur->val - p.second));
            return pair(p.first, cur->val);
        }
        pair<int, int> pl = solve(cur->left);
        pair<int, int> pr = solve(cur->right);
        ans = min(ans, abs(cur->val - pl.second));
        ans = min(ans, abs(cur->val - pr.first));
        return pair(pl.first, pr.second);
    }
    int getMinimumDifference(TreeNode* root) {
        solve(root);
        return ans;
    }
private:
    int ans = INT_MAX;
};