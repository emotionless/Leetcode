class Solution {
public:
    int getMaxLen(vector<int> &nums, int pre) {
        int cnt = 0;
        for (auto num : nums) {
            if (num%2 != pre) {
                cnt++;
                pre =  num%2;
            }
        }
        return cnt;
    }
    int maximumLength(vector<int>& nums) {
        int even = 0, odd = 0;
        for (auto num : nums) {
            if (num%2==0) even++;
            else odd++;
        }
        int ans = max(even, odd);
        
        return max(ans, max(getMaxLen(nums, 0), getMaxLen(nums, 1)));
    }
};