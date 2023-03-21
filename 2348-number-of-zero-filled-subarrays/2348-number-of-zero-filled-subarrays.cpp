class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long cnt = 0;
        for (auto &num : nums) {
            if (num) {
                ans += (cnt*(cnt+1))/2;
                cnt = 0;
            } else cnt++;
        }
        ans += (cnt*(cnt+1))/2;
        return ans;
    }
};