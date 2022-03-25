class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int tot = 0;
        int n = costs.size();
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push(make_pair(abs(costs[i][0] - costs[i][1]), i));
        }
        int a = n / 2;
        int b = a;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int ind = top.second;
            if (costs[ind][0] < costs[ind][1]) {
                if (a > 0) {
                    a--;
                    tot += costs[ind][0];
                } else {
                    b--;
                    tot += costs[ind][1];
                }
            } else {
                if (b > 0) {
                    b--;
                    tot += costs[ind][1];
                } else {
                    a--;
                    tot += costs[ind][0];
                }
            }
        }
        return tot;
    }
};