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
    
    vector<TreeNode*> solve(int st, int ed) {
        if (st == ed) {
            return {new TreeNode(st)};
        } else if (st > ed) {
            return {nullptr};
        }
        vector<TreeNode*> ret;
        for (int i = st; i <= ed; i++) {
            auto lftTrees = solve(st, i-1);
            auto rgtTrees = solve(i + 1, ed);
            for (auto lft : lftTrees) {
                for (auto rgt : rgtTrees) {
                    TreeNode *cur = new TreeNode(i);
                    cur -> left = lft;
                    cur -> right = rgt;
                    ret.push_back(cur);
                }
            }
        }
        return ret;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return solve(1, n);
    }
};