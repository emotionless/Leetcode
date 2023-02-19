/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    int getDepth(TreeNode *cur) {
        if(cur == NULL) return 0;
        return 1 + max(getDepth(cur->left), getDepth(cur->right));
    }
    
    void createZigzagLevel(const TreeNode *cur, const int cl, vector<vector<int>>&ret) {
        if(cur == NULL) return;
        ret[cl].push_back(cur->val);
        createZigzagLevel(cur->left, cl + 1, ret);
        createZigzagLevel(cur->right, cl + 1, ret);
        return;
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int depth = getDepth(root);
        vector<vector<int>> ret;
        ret.resize(depth);
        createZigzagLevel(root, 0, ret);
        for(int i = 1; i < depth; i += 2) {
            reverse(ret[i].begin(), ret[i].end());
        }
        return ret;
    }
};