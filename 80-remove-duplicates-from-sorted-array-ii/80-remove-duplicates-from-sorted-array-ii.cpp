class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        int j = 2;
        int pre1 = nums[1], pre2 = nums[0];
        for (int i = 2; i < n; i++) {
            if (nums[i] != pre2) {
                nums[j++] = nums[i];
            }
            pre2 = pre1;
            pre1 = nums[i];
        }
        return j;
    }
};