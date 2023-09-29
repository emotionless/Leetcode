class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> container;
        for (int i = 0; i < n; i++) {
            container.push_back({intervals[i][0], i});
        }
        sort(container.begin(), container.end());
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            ans[i] = binarySearch(container, intervals[i][1] - 1);
        }
        return ans;
    }
private:
    int binarySearch(vector<pair<int, int>> &container, const int &value) {
        int st = 0, ed = container.size() - 1, mid, ans = -1;
        while (st <= ed) {
            mid = (st + ed) / 2;
            if (container[mid].first > value) {
                ans = container[mid].second;
                ed = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
};