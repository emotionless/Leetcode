class Solution {
    
    
    int getSum(int n, int bad) {
        int sum = (n*(n+1))/2;
        int badSum = (bad*(bad-1))/2;
        return sum - badSum;
    }
    
    public int pivotInteger(int n) {
        int st = 1, ed = n, ans = -1;
        while (st <= ed) {
            int mid = (st + ed) / 2;
            if (getSum(mid, 1) < getSum(n, mid)) {
                st = mid + 1;
            } else if (getSum(mid, 1) > getSum(n, mid)) {
                ed = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
}