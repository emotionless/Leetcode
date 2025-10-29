class Solution {
public:
    int smallestNumber(int n) {
        int ans = 1;
        while (n) {
            ans = ans * 2;
            n = n >> 1;
        }
        return ans - 1;
    }
};