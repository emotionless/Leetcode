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
    const int INF = 100001;
    
    int traverse(TreeNode *cur, int &ans) {
        if (cur == 0) return 0;
        auto v1 = traverse(cur -> left, ans);
        auto v2 = traverse(cur->right, ans);
        if (abs(v1-v2) > 1) ans = false;
        return max(v1 + 1, v2 + 1);
    }
    
    bool isBalanced(TreeNode* root) {
        int ans = 1;
        traverse(root, ans);
        return ans;
    }
};