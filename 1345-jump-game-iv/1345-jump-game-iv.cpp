class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; i++) {
            adj[arr[i]].push_back(i);
        }
        vector<int> cost(n, INT_MAX);
        cost[0] = 0;
        queue<int> q;
        q.push(0);
        unordered_set<int> visited;
        while (!q.empty()) {
            int cn = q.front();
            q.pop();
            if (cn == (n-1)) {
                return cost[cn];
            }
            if (visited.find(arr[cn]) == visited.end()) {
                for (auto v : adj[arr[cn]]) {
                    if (v == cn) continue;
                    if ((cost[cn] + 1) < cost[v]) {
                        cost[v] = cost[cn] + 1;
                        q.push(v);
                    }
                }
            }
            if (cn > 0 && (cost[cn] + 1) < cost[cn - 1]) {
                cost[cn - 1] = cost[cn] + 1;
                q.push(cn - 1);
            }
            if (cn < (n-1) && (cost[cn] + 1) < cost[cn + 1]) {
                cost[cn + 1] = cost[cn] + 1;
                q.push(cn + 1);
            }
            visited.insert(arr[cn]);
        }
        assert(0);
    }
};