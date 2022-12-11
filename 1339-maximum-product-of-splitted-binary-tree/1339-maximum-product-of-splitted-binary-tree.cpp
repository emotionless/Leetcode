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
    
    long long getMaximumProduct(TreeNode *cur, long long &answer) {
        if (cur == nullptr) return 0;
        long long left = getMaximumProduct(cur->left, answer);
        long long right = getMaximumProduct(cur->right, answer);
        
        answer = max(answer, left * (total - left));
        answer = max(answer, right * (total - right));
        
        return cur->val + left + right;
    }
    
    int maxProduct(TreeNode* root) {
        long long answer = 0;
        total = getMaximumProduct(root, answer);
        getMaximumProduct(root, answer);
        return answer%(1000000007);
    }
private:
    long long total;
};