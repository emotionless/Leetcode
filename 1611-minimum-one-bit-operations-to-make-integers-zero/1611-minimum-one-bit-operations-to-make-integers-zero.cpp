// from editorials
class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ans = 0;
        int k = 0;
        int mask = 1;
        
        while (mask <= n) {
            if ((n & mask) != 0) {
                ans = (1 << (k + 1)) - 1 - ans;
            }
            
            mask <<= 1;
            k++;
        }
        
        return ans;
    }
};