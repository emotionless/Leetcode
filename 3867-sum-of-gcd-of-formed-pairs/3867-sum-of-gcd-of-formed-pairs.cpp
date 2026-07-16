class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n, 1);
        int mx = 0;
        for (int i = 0; i < n; i++){
            mx = max(mx, nums[i]);
            prefixGcd[i] = __gcd(mx, nums[i]);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        long long sum = 0;
        for (int i = 0,  j = n - 1; i < j; i++, j--) {
            sum += __gcd(prefixGcd[i], prefixGcd[j]);
        }
        return sum;
    }
};