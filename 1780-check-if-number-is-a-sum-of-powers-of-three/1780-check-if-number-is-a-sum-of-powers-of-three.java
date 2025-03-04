class Solution {
    public boolean checkPowersOfThree(int n) {
        ArrayList<Integer> nums = new ArrayList<>();
        int mul = 1;
        for (int i = 0; mul <= n; i++) {
            nums.add(mul);
            mul = mul * 3;
        }
        Collections.reverse(nums);
        for (int num : nums) {
            if (num <= n) {
                n -= num;
            }
        }
        return n == 0;
    }
}