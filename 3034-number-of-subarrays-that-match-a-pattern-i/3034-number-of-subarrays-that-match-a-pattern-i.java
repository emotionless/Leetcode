class Solution {
    public int countMatchingSubarrays(int[] nums, int[] pattern) {
        int n = nums.length;
        int m = pattern.length;
        
        int cnt = 0;
        for (int i = 1; i <= (n - m); i++) {
            if (doesMatch(i, nums, pattern)) {
                cnt++;
            }
        }
        return cnt;
    }
    
    private boolean doesMatch(int st, int[] nums, int[] pattern) {
        int m = pattern.length;
        for (int i = 0; i < m; i++) {
            int ind = i + st;
            if (pattern[i] == 1 && nums[ind] > nums[ind - 1]) continue;
            else if (pattern[i] == 0 && nums[ind] == nums[ind - 1]) continue;
            else if (pattern[i] == -1 && nums[ind] < nums[ind - 1]) continue;
            else return false;
        }
        return true;
    }
}