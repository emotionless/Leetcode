class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long a = (n>>1)^n;
        return (a&(a+1))==0;
    }
};