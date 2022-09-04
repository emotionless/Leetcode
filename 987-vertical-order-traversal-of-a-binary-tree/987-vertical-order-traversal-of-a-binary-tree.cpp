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

struct node {
    int x, y, val;
    node (int a, int b, int c) {
        x = a, y = b, val = c;
    }
};


struct compare {
    bool operator()(const node &a, const node &b) {
        if (a.x == b.x && a.y == b.y) return -a.val < -b.val;
        else if (a.y == b.y) return -a.x < -b.x;
        else return -a.y < -b.y;
    }
};

class Solution {
public:
    
    void dfs(TreeNode *cur, int x, int y) {
        if (cur == nullptr) return;
        pq.push(node(x, y, cur->val));
        dfs(cur->left, x + 1, y - 1);
        dfs(cur->right, x + 1, y + 1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int>> ans;
        vector<int> save;
        auto top = pq.top();
        pq.pop();
        save.push_back(top.val);
        int prex = top.x;
        int prey = top.y;
        while (!pq.empty()) {
            node curPair = pq.top();
            pq.pop();
            if (curPair.y != prey) {
                ans.push_back(save);
                save.clear();
            }
            save.push_back(curPair.val);
            prex = curPair.x;
            prey = curPair.y;
        }
        ans.push_back(save);
        
        return ans;
    }
private:
    priority_queue<node, vector<node>, compare> pq;
};