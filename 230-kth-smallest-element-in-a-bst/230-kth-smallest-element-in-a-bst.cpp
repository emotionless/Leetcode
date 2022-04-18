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
    
    void bst(TreeNode *cur, int &k, int &ans) {
        if (cur == nullptr) return;
        bst(cur->left, k, ans);
        if (k == 1) {
            ans = cur->val;
        }
        k--;
        if (k > 0) {
            bst(cur->right, k, ans);
        }
        return;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        bst(root, k, ans);
        
        return ans;
    }
};