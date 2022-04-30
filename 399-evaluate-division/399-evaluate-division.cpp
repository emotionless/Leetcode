class Solution {
public:
    int getHash(string str) {
        if (hash.find(str) == hash.end()) {
            hash[str] = (ind++);
        }
        return hash[str];
    }
    
    double ans = -1.0;
    
    bool dfs(int cur, int tar, double x) {
        
        // cout << cur << " " << tar << " " << x << endl;
        if (cur == tar) {
            ans = x;
            return true;
        }
        if (visited.find(cur) != visited.end()) return false;
        visited[cur] = true;
        for(auto v : adj[cur]) {
            if (dfs(v.first, tar, x*v.second))
                return true;
        }
        return false;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i = 0; i < equations.size(); i++) {
            auto v = equations[i];
            adj[getHash(v[0])].push_back(make_pair(getHash(v[1]), values[i]));
            adj[getHash(v[1])].push_back(make_pair(getHash(v[0]), 1.0/values[i]));
        }
        vector<double> res;
        for(auto v : queries) {
            ans = -1.0;
            if (hash.find(v[0]) != hash.end() && hash.find(v[1]) != hash.end()) {
                visited.clear();
                dfs(hash[v[0]], hash[v[1]], 1.0);
            }
            res.push_back(ans);
        }
        return res;
    }
private:
    vector<pair<int, double>> adj[41];
    unordered_map<string, int> hash;
    unordered_map<int, int> visited;
    int ind = 0;
};