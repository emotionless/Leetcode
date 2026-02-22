class Solution {
public:
    int binaryGap(int n) {
        int ind = 0;
        int last = -1;
        int ans = 0;
        while (n > 0) {
            if (n&1) {
                if (last != -1) ans = max(ans, ind - last);
                last  = ind;
            }
            ind++;
            n = n >> 1;
        }
        return ans;
    }
};