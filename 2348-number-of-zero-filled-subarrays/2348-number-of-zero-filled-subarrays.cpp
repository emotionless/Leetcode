class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt = 0;
        long long ans =  0;
        for (auto num : nums) {
            if (num == 0) cnt++;
            else {
                ans += (cnt*(cnt+1ll))/2ll;
                cnt = 0;
            }
        }
        ans += (cnt*(cnt+1ll))/2ll;

        return ans;
    }
};