class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        int n = nums.length;
        ArrayList<Integer> right = new ArrayList<>();
        int[] ans = new int[n];
        int ind = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) {
                ans[ind++] = nums[i];
            } else if (nums[i] > pivot) {
                right.add(nums[i]);
            } else {
                cnt++;
            }
        }
        while (cnt > 0) {
            ans[ind++] = pivot;
            cnt--;
        }
        for (int num : right) {
            ans[ind++] = num;
        }
        return ans;
    }
}