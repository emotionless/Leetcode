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
    
    void inorderTraverse(TreeNode *cur) {
        if (cur == nullptr) {
            return;
        }
        inorderTraverse(cur->left);
        nodeList.push_back(cur->val);
        inorderTraverse(cur->right);
        
        return;
    }
    
    TreeNode* divideAndConquer(int st, int ed) {
        if (st > ed) return nullptr;
        int mid = (st + ed) / 2;
        TreeNode *cur = new TreeNode(nodeList[mid]);
        cur -> left = divideAndConquer(st, mid - 1);
        cur -> right = divideAndConquer(mid + 1, ed);
        return cur;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        inorderTraverse(root);
        return divideAndConquer(0, nodeList.size() - 1);
    }
private:
    vector<int> nodeList;
    TreeNode *ans = nullptr;
};