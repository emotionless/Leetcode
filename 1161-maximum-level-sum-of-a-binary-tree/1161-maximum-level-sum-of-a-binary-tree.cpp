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
    
    void dfs(TreeNode *cur, int lvl) {
        if (cur == nullptr){
            return;
        }
        sumOfEachLevel[lvl] += cur->val;
        dfs(cur->left, lvl + 1);
        dfs(cur->right, lvl + 1);
        
        return;
    }
    
    int maxLevelSum(TreeNode* root) {
        dfs(root, 1);
        int ans = 0, mx = INT_MIN;
        for(auto it : sumOfEachLevel) {
            if (it.second > mx) {
                ans = it.first;
                mx = it.second;
            } else if(it.second == mx) {
                ans = min(ans, it.first);
            }
        }
        return ans;
    }
private:
    map<int, int> sumOfEachLevel;
};