class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        sort(items.begin(), items.end());
        vector<int> cost;
        int mx = 0;
        for (auto &v : items) {
            mx = max(mx, v[1]);
            cost.push_back(mx);
        }
        vector<int> ret;
        for (auto &v : queries) {
            int st = 0, ed = n - 1;
            int ans = -1;
            while (st <= ed) {
                int mid = (st + ed) / 2;
                if (items[mid][0] <= v) {
                    ans = mid;
                    st = mid + 1;
                } else {
                    ed = mid - 1;
                }
            }
            if (ans != -1) {
                ret.push_back(cost[ans]);
            } else {
                ret.push_back(0);
            }
        }
        return ret;
    }
};