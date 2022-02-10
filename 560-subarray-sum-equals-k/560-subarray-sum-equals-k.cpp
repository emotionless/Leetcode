class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int ans = 0;
        unordered_map<int, int> counter;
        counter[sum] = 1;
        for (auto num : nums) {
            sum += num;
            ans += counter[sum-k];
            counter[sum]++;
        }
        return ans;
    }
};