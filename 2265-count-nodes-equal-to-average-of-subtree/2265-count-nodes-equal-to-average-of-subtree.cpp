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
    
    pair<int, int> getCount(TreeNode *cur, int &cnt) {
        if (cur == nullptr) return {0, 0};
        auto left = getCount(cur->left, cnt);
        auto right = getCount(cur->right, cnt);
        if ((left.first + right.first + cur->val) / (left.second + right.second + 1) == cur->val) cnt++;
        return {(left.first + right.first + cur->val), (left.second + right.second + 1)};
    }
    
    int averageOfSubtree(TreeNode* root) {
        int cnt = 0;
        getCount(root, cnt);
        return cnt;
    }
};