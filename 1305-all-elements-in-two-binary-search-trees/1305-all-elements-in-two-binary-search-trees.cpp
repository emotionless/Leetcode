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
    
    void dfs(TreeNode *node, stack<int> &store) {
        if (node == nullptr) return;
        dfs(node->left, store);
        store.push(node->val);
        dfs(node->right, store);
        
        return;
    } 
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<int> list1, list2;
        dfs(root1, list1);
        dfs(root2, list2);
        vector<int> ans(list1.size() + list2.size(), 0);
        int ind = list1.size() + list2.size() - 1;
        while (list1.size() || list2.size()) {
            int num1 = INT_MIN, num2 = INT_MIN;
            if (list1.size()) {
                num1 = list1.top();
            }
            if (list2.size()) {
                num2 = list2.top();
            }
            if (num1 > num2) {
                ans[ind--] = num1;
                list1.pop();
            } else {
                ans[ind--] = num2;
                list2.pop();
            }
        }
        return ans;
    }
};