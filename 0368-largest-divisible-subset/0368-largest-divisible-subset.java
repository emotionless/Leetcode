class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        List<Integer> list = new ArrayList<>();
        Arrays.sort(nums);
        int ans = 0;
        int pos = 0;
        for (int i = 0; i < nums.length; i++) {
            int mx = 1, ind = i;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0) {
                    if ((list.get(j) + 1) > mx) {
                        mx = list.get(j) + 1;
                        ind = j;
                    }
                }
            }
            if (mx > ans) {
                ans = mx;
                pos = i;
            }
            list.add(mx);
        }
        List<Integer> res = new ArrayList<>();
        int num = nums[pos];
        for (int i = nums.length - 1; i >= 0; i--) {
            if (num % nums[i] == 0 && list.get(i) == ans) {
                res.add(nums[i]);
                num = nums[i];
                ans--;
            }
        }
        
        return res;
    }
}