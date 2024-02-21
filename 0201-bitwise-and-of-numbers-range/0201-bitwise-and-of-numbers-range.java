class Solution {
    public int rangeBitwiseAnd(int left, int right) {
        int diff = right - left;
        int ans = right&left;
        int mul = 1;
        while (mul <= diff) {
            ans = ans&(~mul);
            mul = mul * 2;
            if (ans == 0) break;
        }
        return ans;
    }
}