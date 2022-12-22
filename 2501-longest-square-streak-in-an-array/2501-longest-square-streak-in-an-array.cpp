class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> seen;
        for (auto &num : nums) {
            seen.insert(num);
        }
        int ans = 0;
        int cnt = 0;
        for (auto &num : nums) {
            int cur = num;
            int cnt = 0;
            while (seen.find(cur) != seen.end()) {
                int sq = sqrt(cur);
                cnt++;
                if (sq*sq != cur) break;
                cur = sq;
            }
            ans = max(ans, cnt);
        }
        return ans == 1? -1 : ans;
    }
};