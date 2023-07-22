class Solution {
public:
    bool checkArray(vector<int> nums, int k) {
        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (cnt > nums[i]) return false;
            nums[i] -= cnt;
            cnt += nums[i];
            if (i >= (k - 1)) {
                cnt -= nums[i-k+1];
            }
        }
        return cnt == 0;
    }
};