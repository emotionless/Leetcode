class Solution {
public:
    int smallestValue(int n) {
        while (n) {
            int num = n;
            int sum = 0;
            for (int i = 2; i <= num; i++) {
                while (num%i == 0) {
                    sum += i;
                    num /= i;
                }
            }
            if (sum == n) break;
            n = sum;
        }
        return n;
    }
};