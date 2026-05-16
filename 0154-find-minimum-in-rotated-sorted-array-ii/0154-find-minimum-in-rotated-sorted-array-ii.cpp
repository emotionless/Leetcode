class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0, ed = nums.size() - 1, ans = INT_MAX;
        while (st <= ed) {
            int mid = (st + ed) / 2;
            ans = min(ans, nums[mid]);
            if (nums[st] == nums[ed]) {
                ans = min(ans, nums[st]);
                st++;
                ed--;
            } else if (nums[mid] == nums[ed]){
                ans = min(ans, nums[mid]);
                ed = mid - 1;
            } else if (nums[mid] == nums[st]) {
                ans = min(ans, nums[mid]);
                st = mid + 1;
            } else if (nums[mid] > nums[st]) {
                ans = min(ans, nums[st]);
                st = mid + 1;
            } else {
                ed = mid - 1;
            }
        }
        return ans;
    }
};