class Solution {
public:
    vector<int> par;
    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        par.resize(n);
        for(int i = 0; i < n; i++) par[i] = i;
        int cnt = 0;
        for(auto v : connections) {
            int px = find(v[0]);
            int py = find(v[1]);
            par[px] = py; 
        }
        for(int i = 0; i < n; i++) {
            cnt += (par[i] == i? 1 : 0);
        }
        int m = connections.size();
        if (m < (n-1)) return -1;
        return cnt - 1;
    }
};