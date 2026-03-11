class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int ret = 0;
        bool found = false;
        for (int i = 30; i >= 0; i--) {
            if (n&(1<<i)) {
                found = true;
            }
            if (!(n&(1<<i)) && found) {
                ret |= (1<<i);
            }
        }
        return ret;
    }
};