class Solution {
public:
    int need(int sum) {
        return (sum + numOfSeats - 1) / numOfSeats;
    }
    pair<long long, int> solve(int cur, int pre) {
        long long ret = 0;
        int sum = 1;
        for (auto &v : adj[cur]) {
            if (v != pre) {
                auto res = solve(v, cur);
                ret += res.first;
                sum += res.second;
            }
        }
        ret += need(sum);
        return {ret, sum};
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        adj.resize(n + 1);
        for (auto &road : roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }
        numOfSeats = seats;
        auto res = solve(0, 0);
        return res.first - need(res.second);
    }
private:
    int numOfSeats;
    vector<vector<int>> adj;
};