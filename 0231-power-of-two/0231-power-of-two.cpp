class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 0) return false;
        int sq = __builtin_popcount(n);
        return sq == 1;
    }
};