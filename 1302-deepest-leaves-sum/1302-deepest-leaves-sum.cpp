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
    
    void dfs(TreeNode *cur, int l) {
        if (cur == nullptr) return;
        if (l == level) {
            sum += cur->val;
        } else if (l > level) {
            sum = cur->val;
            level = l;
        }
        dfs(cur->left, l + 1);
        dfs(cur->right, l + 1);
        
        return;
    }
    
    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 0);
        return sum;
    }
private:
    int level;
    int sum = 0;
};