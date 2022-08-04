class Solution {
public:
    int mirrorReflection(int p, int q) {
        int n = 1, m = 1;
        while (n*p != m*q) {
            m++;
            n = (m*q) / p;
        }
        if (n % 2 == 0 && m % 2 == 1) return 0;
        else if (n % 2 == 1 && m % 2 == 1) return 1;
        else if (n % 2 == 1 && m % 2 == 0) return 2;
        return -1;
    }
};