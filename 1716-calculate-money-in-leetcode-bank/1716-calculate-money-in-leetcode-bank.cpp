class Solution {
public:
    int totalMoney(int n) {
        int sum = 0;
        int cur = 6;
        for (int i = 0; i < n; i++) {
            if (i%7 == 0) {
                cur = cur - 6;
            }
            cur++;
            sum += cur;
        }
        return sum;
    }
};