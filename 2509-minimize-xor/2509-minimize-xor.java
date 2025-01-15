class Solution {
    int numOfBit(int num) {
        int cnt = 0;
        for (int i = 0; i < 31; i++) {
            if ((num&(1<<i)) > 0) cnt++;
        }
        return cnt;
    }
    public int minimizeXor(int num1, int num2) {
        int res = 0;
        int cnt = numOfBit(num2);
        for (int i = 30; i >= 0 && cnt > 0; i--) {
            if ((num1&(1<<i)) > 0 || cnt > i) {
                cnt--;
                res |= (1<<i);
            }
        }
        return res;
    }
}