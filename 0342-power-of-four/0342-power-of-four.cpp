/**

EXPLANATION:

num>0 then only it can be power of 4 . 4^0=1 , 4^1=4 ..
only 1 bit is on then number is power of 2 .
therefore in every power of 4 number will have only 1 set bit.
(4^n - 1) % 3 == 0
Mathematical proof:
3.1 4^n - 1 = (2^n + 1) * (2^n - 1)
3.2 among any 3 consecutive numbers, there must be one that is a multiple of 3
among (2^n-1), (2^n), (2^n+1), one of them must be a multiple of 3, and (2^n) cannot be the one, therefore either (2^n-1) or (2^n+1) must be a multiple of 3, and 4^n-1 must be a multiple of 3 as well

*/

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        if (n&(n-1)) return false;

        return (n-1) % 3 == 0;
    }
};