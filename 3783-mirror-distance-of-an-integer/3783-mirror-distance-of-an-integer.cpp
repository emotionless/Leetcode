class Solution {
public:
int reverseNumber(int num) {
        int ret = 0;
        while (num > 0) {
            ret = ret * 10 + num % 10;
            num /= 10;
        }
        return ret;
    }
    int mirrorDistance(int n) {
        return  abs(n - reverseNumber(n));
    }
};