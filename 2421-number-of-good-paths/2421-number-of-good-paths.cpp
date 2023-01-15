class Solution {
public:
    
    int calculate(vector<int> &arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        int ans = 0;
        for (auto &v : arr) {
            sum -= v;
            ans += v*(sum + 1);
        }
        return ans;
    }
    
    int find(int u) {
        if (par.find(u) == par.end()) return -1;
        if (par[u] == u) return u;
        return par[u] = find(par[u]);
    }
    
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        adj.resize(n);
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        priority_queue<pair<int, int>>pq;
        for (int i = 0; i < n; i++) {
            pq.push({-vals[i], i});
        }
        int ans = n;
        int pre = -1;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            if (top.first != pre) {
                counter.clear();
            }
            int cur = top.second;
            // cout << cur << endl;
            vector<int> tmp;
            counter[cur] = 1;
            par[cur] = cur;
            for (auto &v : adj[cur]) {
                int pv = find(v);
                if (pv == -1) continue;
                par[pv] = cur;
                counter[cur] += counter[pv];
                if (counter[pv])
                tmp.push_back(counter[pv]);
                // cout << pv << " has " << counter[pv] << " ";
            }
            // cout << endl;
            
            ans += calculate(tmp);
            // cout << "ans: " << ans << endl;
            pre = top.first;
        }
        return ans;
    }
private:
    unordered_map<int, int> par, counter;
    vector<vector<int>> adj;
    
};