class Solution {
public:
    
    void reachableNodes(int currentNode, vector<int> &nodes) {
        if (vis[currentNode]) return;
        vis[currentNode] = true;
        nodes.push_back(currentNode);
        for (auto &v : adj[currentNode]) {
            reachableNodes(v, nodes);
        }
    }
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        adj.clear();
        counter.clear();
        adj.resize(n);
        for (auto edge : edges) {
            counter[edge[0]]++;
            counter[edge[1]]++;
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vis.resize(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                bool flag = false;
                vector<int> nodes;
                reachableNodes(i, nodes);
                for (auto node : nodes) {
                    if (counter[node] != (nodes.size() - 1)) {
                        flag = true;
                        break;
                    }
                }
                if (!flag) {
                    ans++;
                }
            }
        }
        return ans;
    }
private:
    unordered_map<int, int> counter;
    vector<vector<int>> adj;
    vector<bool> vis;
};