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
    
    void dfs(TreeNode *cur, int &sum) {
        if (cur == nullptr) return;
        
        dfs(cur->right, sum);
        sum += cur->val;
        cur->val = sum;
        dfs(cur->left, sum);
        
        return;
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        dfs(root, sum);
        
        return root;
    }
};