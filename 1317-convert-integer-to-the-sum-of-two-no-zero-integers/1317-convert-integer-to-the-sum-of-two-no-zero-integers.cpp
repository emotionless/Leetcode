class Solution {
public:
    bool isNoZero(int num) {
        while (num) {
            if (num%10 == 0) {
                return false;
            }
            num /= 10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++) {
            if (isNoZero(i) && isNoZero(n-i)) {
                return {i, n-i};
            }
        }
        return {0, 0};
    }
};