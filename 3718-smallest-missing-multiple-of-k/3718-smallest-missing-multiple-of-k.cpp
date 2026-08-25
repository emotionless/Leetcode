class Solution {
public:
    int missingMultiple(vector<int>& nums, int kk) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ind = 0;
        int k = kk;
        while (true) {
            while (ind < n && nums[ind] < k) ind++;
            if (ind == n) return k;
            if (nums[ind] == k) k = k + kk;
            else return k;
        }
    }
};