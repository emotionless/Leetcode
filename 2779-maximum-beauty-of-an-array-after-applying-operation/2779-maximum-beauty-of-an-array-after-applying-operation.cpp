class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        map<int, int> counter;
        for (auto &num : nums) {
            counter[num - k]++;
            counter[num+k+1]--;
        }
        int count = 0;
        int ans = 0;
        for (auto mp : counter) {
            count += mp.second;
            ans = max(ans, count);
        }
        return ans;
    }
};