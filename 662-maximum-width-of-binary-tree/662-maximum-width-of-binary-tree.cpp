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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        long long ans = 0;
        q.push(make_pair(root, 1ll));
        while (!q.empty()) {
            queue<pair<TreeNode*, long long>> tmp;
            long long mn = LLONG_MAX, mx = LLONG_MIN;
            long long lowest = LLONG_MAX;
            while (!q.empty()) {
                auto top = q.front();
                mn = min(mn, top.second);
                mx = max(mx, top.second);
                q.pop();
                if (top.first->left) {
                    lowest = min(lowest, top.second*2);
                    tmp.push(make_pair(top.first->left, top.second * 2 - lowest + 1));
                }
                if (top.first->right) {
                    lowest = min(lowest, top.second*2 + 1);
                    tmp.push(make_pair(top.first->right, top.second *2ll + 1 - lowest + 1));
                }
            }
            ans = max(ans, mx - mn + 1);
            q = tmp;
        }
        return ans;
    }
};