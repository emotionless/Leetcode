class Solution {
public:
    const long long INF = 1e9;
    void floydWarshall(vector<vector<long long>> &dist) {
        int sz = dist.size();
        for (int k = 0; k < sz; k++) {
            for (int i = 0; i < sz; i++) {
                for (int j = 0; j < sz; j++) {
                    if ((dist[i][k] + dist[k][j]) < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>>dist(26,vector<long long>(26,INF));
        int sz = original.size();
        // cout << sz << endl;
        for (int i = 0; i < sz; i++) {
            int id1 = original[i] - 'a';
            int id2 = changed[i] - 'a';
            
            dist[id1][id2] = min(cost[i] + 0ll, dist[id1][id2]);
        }
        for (int i = 0; i < 26; i++) dist[i][i] = 0;
        floydWarshall(dist);
        // cout << dist[0][4] << endl;
        long long ans = 0;
        int len = source.size();
        for (int i = 0; i < len; i++) {
            int o = source[i] - 'a';
            int c = target[i] - 'a';
            if (o == c) continue;
            ans += dist[o][c];
            if (dist[o][c] >=  INF) return -1;
        }
        return ans;
    }
};