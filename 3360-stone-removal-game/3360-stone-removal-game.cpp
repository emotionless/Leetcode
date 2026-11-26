class Solution {
public:
    bool canAliceWin(int n) {
        bool bob  = false;
        int cur = 10;
        while (n >= 0) {
            if (cur > n) return bob;
            n -= cur;
            cur--;
            bob = 1 - bob;
        }
        return true;
    }
};