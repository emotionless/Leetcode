class Solution {
public:

    bool possible(int value, long long k) {
        priority_queue<pair<long long, int>> pq;
        unordered_set<int> vis;

        pq.push({0, 0});

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int u = top.second;
            long long cost = -top.first;

            if (vis.find(u) != vis.end()) continue;
            if (cost > k) continue;
            if (u == (n-1)) return true;

            vis.insert(u);

            for (auto edge : adj[u]) {
                int v = edge.first;
                long long c = edge.second;
                if (c < value) continue;
                if (vis.find(v) != vis.end()) continue;
                long long newCost = cost + c;
                pq.push({-newCost, v});
            }
        }
        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        n = online.size();
        for (auto &edge : edges) {
            if (online[ edge[0] ] == 0 || online[ edge[1] ] == 0) continue;
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        long long st = 0, ed = 1e9;
        long long ans = -1;

        while (st <= ed) {
            long long mid = (st + ed) / 2ll;
            if (possible(mid, k)) {
                ans = mid;
                st = mid + 1ll;
            } else {
                ed = mid - 1ll;
            }
        }
        return ans;
    }
private:
    unordered_map<int, vector<pair<int, int>>> adj;
    int n;
};