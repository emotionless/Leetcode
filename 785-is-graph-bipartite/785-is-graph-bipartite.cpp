class Solution {
public:
    
    bool doColor(int u, const vector<vector<int>> &graph, int c, int color[]) {
        if (color[u] != 0) return c == color[u];
        bool ret = true;
        color[u] = c;
        for(auto v : graph[u]) {
            ret = ret & doColor(v, graph, c%2 + 1, color);
        }
        return ret;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int color[n];
        memset(color, 0, sizeof color);     // 0 - no color, 1 = black, 2 - white
        int ans = true;
        for(int i = 0; i < n; i++) {
            if (!color[i]) {
                ans = ans & doColor(i, graph, 1, color);
            }
        }
        return ans;
    }
};