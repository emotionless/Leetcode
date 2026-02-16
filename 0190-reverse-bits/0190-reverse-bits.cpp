class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for(int i = 0, j = 31; i <= j; i++, j--) {
            int b1 = (n&(1<<i)) ? 1:0;
            int b2 = (n&(1<<j))?1:0;
            // cout << b1 << " " << b2 << endl;
            if (b1) ans = ans | (1<<j);
            if (b2) ans = ans | (1<<i);
            // n = n & ((b2?1ll<<j:0) ^ ~(1ll<<j));
            // n = n & ((b1?1ll<<i:0) ^ ~(1ll<<i));
        }
        return ans;
    }
};