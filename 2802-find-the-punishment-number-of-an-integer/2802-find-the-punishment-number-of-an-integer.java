class Solution {
    boolean getPanishment(int num, int target) {
        if (target < 0 || num < target) {
            return false;
        }
        if (num == target) return true;
        
        return getPanishment(num / 10, target - num % 10) ||
        getPanishment(num / 100, target - num % 100) ||
        getPanishment(num / 1000, target - num % 1000);
    }
    public int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (getPanishment(i*i, i)) {
                ans += i*i;
            }
        }
        return ans;
    }
}