class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        List<Pair<Integer, Integer>> list = new ArrayList<Pair<Integer, Integer>>();
        Arrays.sort(nums);
        int ans = 0;
        int pos = 0;
        for (int i = 0; i < nums.length; i++) {
            int mx = 1, ind = i;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0) {
                    if ((list.get(j).getKey() + 1) > mx) {
                        mx = list.get(j).getKey() + 1;
                        ind = j;
                    }
                }
            }
            if (mx > ans) {
                ans = mx;
                pos = i;
            }
            list.add(new Pair(mx, ind));
        }
        List<Integer> res = new ArrayList<>();
        res.add(nums[pos]);
        while (pos != list.get(pos).getValue()) {
            pos = list.get(pos).getValue();
            res.add(nums[pos]);
        } 
        
        return res;
    }
}