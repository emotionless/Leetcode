class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto v : tickets) {
            adj[v[0]].insert(v[1]);
        }
        vector<string> ans;
        solve("JFK", ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
private:
    unordered_map<string, multiset<string>> adj;
    
    void solve(string str, vector<string> &ans) {
        while (adj[str].size() > 0) {
            auto nxt = adj[str].begin();
            string nxtAirport = *nxt;
            adj[str].erase(nxt);
            solve(nxtAirport, ans);
        }
        ans.push_back(str);
    }
};