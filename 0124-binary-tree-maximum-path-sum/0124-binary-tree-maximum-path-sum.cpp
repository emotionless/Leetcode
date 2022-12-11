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
    int ans = INT_MIN;
    
    int DFS(TreeNode *cur) {
        if(cur == NULL) return 0;
        int l = 0, r = 0;
        if (cur -> left) l = DFS(cur->left);
        if (cur -> right) r = DFS(cur-> right);
        l = max(0, l);
        r = max(0, r);
        ans = max(ans, l + r + cur -> val);
        return cur -> val + max(l, r);
    }
    
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        DFS(root);
        return ans;
    }
};