class Solution {
    Map<Integer, Integer> dp = new HashMap<>();
    public int integerBreak(int n) {
        if (n == 2) return 1;
        else if (n == 3) return 2;
        else return solve(n);
    }
    
    public int solve(int num) {
        if (num <= 3) return num;
        if (dp.containsKey(num)) return dp.get(num);
        dp.put(num, 0);
        int ret = num;
        for (int i = 1; i < num; i++) {
            ret = Math.max(ret, i*solve(num - i));
        }
        dp.put(num, ret);
        return ret;
    }
}