class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467%n == 0;
        if (n <= 0) return false;
        while (n >= 3) {
            if (n%3) return false;
            n /= 3;
        }
        return n == 1;
    }
};