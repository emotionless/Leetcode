class Solution {
    public int tupleSameProduct(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int k = i + 1; k < n; k++) {
                int j = i + 1;
                int l = k + 1;
                while (j < k && l < n) {
                    if (nums[i]*nums[l] < nums[j]*nums[k]) {
                        l++;
                    } else if (nums[i]*nums[l] > nums[j]*nums[k]) {
                        j++;
                    } else {
                        ans++;
                        j++;
                    }
                }
            }
        }
        return ans * 8;
    }
}