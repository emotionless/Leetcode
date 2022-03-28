class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        priority_queue<int> left;
        priority_queue<int, vector<int>, greater<>> right;
        int n = nums.size();
        int N = n / 3;
        long long total = 0;
        vector<long long> tmp(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            right.push(nums[i]);
            total += nums[i];
            if (right.size() > N) {
                total -= right.top();
                right.pop();
            }
            tmp[i] = total;
        }
        total = 0;
        long long ans = LLONG_MAX;
        for (int i = 0; i < N*2; i++) {
            left.push(nums[i]);
            total += nums[i];
            if (left.size() > N) {
                total -= left.top();
                left.pop();
            }
            if (left.size() == N) {
                ans = min(ans, total - tmp[i + 1]);
            }
        }
        return ans;
    }
};