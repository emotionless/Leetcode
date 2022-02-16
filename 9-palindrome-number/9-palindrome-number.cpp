class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int num = x;
        long long rev = 0;
        while (num) {
            int d = num % 10;
            rev = rev * 10 + d;
            num /= 10;
        }
        return rev == x;
    }
};