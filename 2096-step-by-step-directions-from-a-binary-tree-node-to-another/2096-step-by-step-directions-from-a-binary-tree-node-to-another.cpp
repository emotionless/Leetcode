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
    
    void dfs(TreeNode *cur, unordered_map<TreeNode*, pair<TreeNode*, char>> &parentsMap) {
        if (cur == nullptr) return;
        if (cur->val == startValue) {
            start = cur;
        }
        if (cur->val == endValue) {
            end = cur;
        }
        parentsMap[cur->left] = make_pair(cur, 'L');
        dfs(cur->left, parentsMap);
        parentsMap[cur->right] = make_pair(cur, 'R');
        dfs(cur->right, parentsMap);
        return;
    }
    
    string makeUpMove(int times) {
        string ret = "";
        while (times--) {
            ret += 'U';
        }
        return ret;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        unordered_map<TreeNode*, pair<TreeNode*, char>> parentsMap;
        this->startValue = startValue;
        this->endValue = destValue;
        dfs(root, parentsMap);
        TreeNode *cur = start;
        string first = "";
        while (cur != nullptr) {
            auto p = parentsMap[cur];
            first += p.second;
            cur = p.first;
        }
        cur = end;
        string second = "";
        while (cur != nullptr) {
            auto p = parentsMap[cur];
            second += p.second;
            cur = p.first;
        }
        // cout << first << "\n" << second << endl;
        int ind1 = first.size() - 1;
        int ind2 = second.size() - 1;
        while (ind1 >= 0 && ind2 >= 0) {
            if (first[ind1] != second[ind2]) break;
            ind1--;
            ind2--;
        }
        string ans = makeUpMove(ind1 + 1);
        reverse(second.begin(), second.begin() + ind2 + 1);
        return ans + second.substr(0, ind2 + 1);
    }
private:
    TreeNode *start, *end;
    int startValue, endValue;
};