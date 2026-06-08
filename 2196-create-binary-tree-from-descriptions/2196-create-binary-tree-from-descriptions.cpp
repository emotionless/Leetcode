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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> hashMap;
        unordered_map<int, bool> isRoot;
        for (auto v : descriptions) {
            TreeNode *par = NULL;
            if (hashMap.find(v[0])  != hashMap.end()) par = hashMap[v[0]];
            else par = new TreeNode(v[0]);

            TreeNode *child = NULL;
            if (hashMap.find(v[1]) != hashMap.end()) child = hashMap[v[1]];
            else child = new TreeNode(v[1]);

            hashMap[v[0]] = par;
            hashMap[v[1]] = child;

            if(v[2]) par->left = child;
            else par->right=child;

            isRoot[v[1]] = false;
        }
        for (auto v : descriptions) {
            if (isRoot.find(v[0]) == isRoot.end()) return hashMap[v[0]];
        }
        return NULL;
    }

};