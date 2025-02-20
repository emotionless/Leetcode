class Solution {
    public String findDifferentBinaryString(String[] nums) {
        int n = nums.length;
        Set<Integer> set = new HashSet<>();
        for (String num : nums) {
            set.add(Integer.parseInt(num, 2));
        }
        int num = 0;
        while (true) {
            if (!set.contains(num)) {
                String ans = Integer.toBinaryString(num);
                while (ans.length() < n) {
                    ans = "0" + ans;
                }
                return ans;
            }
            num++;
        }
    }
}