class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<pair<int, int>> q;
        int n = nums.size();
        for (int i = n - 1; i >= 0; i--) {
            while (!q.empty() && (q.front().second - i) > k) {
                q.pop_front();
            }
            int mx = nums[i];
            if (!q.empty()) {
                mx += q.front().first;
            }
            while (!q.empty() && q.back().first <= mx) {
                q.pop_back();
            }
            q.push_back({mx, i});
        }
        return q.back().first;
    }
};