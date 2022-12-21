class Solution {
public:
    vector<int> adj[2001];
    int col[2001];
    
    bool DFS(int u, int c) {
        if (col[u] != -1) return (col[u] == c);
        col[u] = c;
        int ret = true;
        for (auto v : adj[u]) {
            ret = ret & DFS(v, 1 - c);
        }
        return ret;
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        for(auto v : dislikes) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        bool ck = true;
        memset(col, -1, sizeof col);
        for(int i = 1; i <= N; i++) {
            if (col[i] == -1) {
                ck = ck & DFS(i, 0);
            }
        }
        return ck;
    }
};