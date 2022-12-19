class Solution {
public:
    
    bool dfs(int cur, int dest) {
        if (cur == dest) return true;
        if (visited.count(cur)) return false;
        visited.insert(cur);
        int ret = 0;
        for (auto &v : connection[cur]) {
            ret = ret | dfs(v, dest);
        }
        return ret;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        connection.resize(n);
        for (auto &v : edges) {
            connection[v[0]].push_back(v[1]);
            connection[v[1]].push_back(v[0]);
        }
        return dfs(source, destination);
    }
private:
    vector<vector<int>> connection;
    unordered_set<int> visited;
};