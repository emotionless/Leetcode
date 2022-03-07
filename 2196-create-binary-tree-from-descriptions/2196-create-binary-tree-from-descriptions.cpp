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
    
    TreeNode* getHash(int v) {
        if (hashMap.find(v) != hashMap.end()) return hashMap[v];
        return hashMap[v] = new TreeNode(v);
    }
    
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> vis;
        for (auto v : descriptions) {
            vis.insert(v[1]); 
        }
        int val = 0;
        for (auto v : descriptions) {
            TreeNode* from = getHash(v[0]);
            TreeNode* to = getHash(v[1]);
            if (vis.find(v[0]) == vis.end()) val = v[0];
            if (vis.find(v[1]) == vis.end()) val = v[1];
            
            if (v[2]) {
                from->left = to;
            } else {
                from->right = to;
            }
        }
        return hashMap[val];
    }
private:
    map<int, TreeNode*> hashMap;
};