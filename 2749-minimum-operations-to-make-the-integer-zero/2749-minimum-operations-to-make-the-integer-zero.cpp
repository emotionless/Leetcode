class Solution {
public:
    int makeTheIntegerZero(long long num1, long long num2) {
        for (int i = 1; i < 61; i++) {
            if (__builtin_popcountll(num1 - num2 * i) <= i && i <= (num1 - num2*i)) return i;
        }
        return -1;
    }
};