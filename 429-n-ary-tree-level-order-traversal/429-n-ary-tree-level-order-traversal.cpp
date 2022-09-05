/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) return {};
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> ans;
        while (!q.empty()) {
            vector<int> currentNodes;
            queue<Node*> tmpQ;
            while (!q.empty()) {
                auto node = q.front();
                q.pop();
                currentNodes.push_back(node->val);
                for (auto v : node->children) {
                    tmpQ.push(v);
                }
            }
            q = tmpQ;
            ans.push_back(currentNodes);
        }
        return ans;
    }
};