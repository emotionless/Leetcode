class Solution {
public:
    bool isPerfectlyGood(int d) {
        return d == 2 || d == 5 || d == 6 || d == 9;
    }
    
    bool isGood(int d) {
        if (d == 3 || d == 4 || d == 7) return false;
        return true;
    }
    
    bool isGoodNumber(int num) {
        bool p = false;
        while  (num) {
            int d = num % 10;
            if (!isGood(d)) return  false;
            if (isPerfectlyGood(d)) p = true;
            num  /= 10;
        }
        return p;
    }
    int rotatedDigits(int n) {
        int ans = 0;
        for (int i = 1; i <= n;i++)  {
            if (isGoodNumber(i)) ans++;
        }
        return ans;
    }
};