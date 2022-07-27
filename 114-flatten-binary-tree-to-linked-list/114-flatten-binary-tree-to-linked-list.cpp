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
    void flatten(TreeNode* root) {
        TreeNode *cur = root;
        stack< TreeNode* > ST;
        while(cur != NULL) {
            if(cur->right != NULL && cur->left != NULL) {
                ST.push(cur->right);
            }
            if(cur -> left == NULL && cur->right == NULL) {
                if(!ST.empty()) {
                    cur->right = ST.top();
                    ST.pop();
                } else {
                    break;
                }
            } else {
                if(cur->left != NULL) {
                    cur->right = cur->left;
                }
            }
            cur -> left = NULL;
            cur = cur->right;
            cout<<cur->val<<endl;
        }
    }
};