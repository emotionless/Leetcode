class Solution {
    public String triangleType(int[] nums) {
        int a = Math.min(nums[0], Math.min(nums[1], nums[2]));
        int c = Math.max(nums[0], Math.max(nums[1], nums[2]));
        int b = nums[0] + nums[1] + nums[2] - a - c;
        if ((a+b) <= c) return "none";
        else if (a == b && b == c && c == a) return "equilateral";
        else  if (a == b || b == c || c == a) return "isosceles";
        else return "scalene";
    }
}