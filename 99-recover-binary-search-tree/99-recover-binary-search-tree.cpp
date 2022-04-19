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
    
    void inorder(TreeNode *cur) {
        if (cur == nullptr) return;
        
        inorder(cur->left);
        nodes.push_back(cur->val);
        inorder(cur->right);
    }
    
    void dfs(TreeNode *cur, int first, int second) {
        if (cur == nullptr) return;
        if (cur->val == first) {
            cur->val = second;
        } else if (cur->val == second) {
            cur->val = first;
        }
        dfs(cur->left, first, second);
        dfs(cur->right, first, second);
        
    }
    
    void recoverTree(TreeNode* root) {
        inorder(root);
        vector<int> save;
        save = nodes;
        sort(nodes.begin(), nodes.end());
        int first = 0, second = 0;
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i] != save[i]) {
                if (first) second = save[i];
                else first = save[i];
            }
        }
        dfs(root, first, second);
    }
private:
    vector<int> nodes;
};