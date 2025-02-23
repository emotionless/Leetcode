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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        unordered_map<int, int> pos;
        for (int i = 0; i < post.size(); i++) {
            pos[ post[i] ] = i;
        }
        int n = pre.size();
        int prevPos = pre.size();
        stack<TreeNode*> container;
        TreeNode *root = nullptr;
        for (int i = 0; i < pre.size(); i++) {
            int cur = pre[i];
            int p = pos[cur];
            TreeNode *node = new TreeNode(cur);
            if (root == nullptr) root = node;
            if (p < prevPos) {
                if (prevPos != n) {
                    container.top()->left = node;
                }
                container.push(node);
            } else {
                
                while(!container.empty()) {
                    if (pos[container.top()->val] > p) break;
                    container.pop();
                }
                
                container.top()->right = node;
                container.pop();
                container.push(node);
            }
            prevPos = p;
        }
        return root;
    }
};