class Solution {
    public int rangeBitwiseAnd(int left, int right) {
        int diff = right - left;
        int ans = right&left;
        int mul = 0;
        System.out.println(ans);
        while ((1<<mul) <= diff) {
            ans = ans&(~(1<<mul));
            mul++;
            if (ans == 0) break;
        }
        return ans;
    }
}