class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n =  nums.size();
        vector<int> counter(value, 0);
        for (auto num : nums) {
            num = ((num%value) + value) % value;
            counter[num]++;
        }
        int ans = n;
        for (int i = 0; i < n && i < value; i++) {
            int times = counter[i%value];
            ans = min(ans, i + value*times);
        }
        return ans;
    }
};