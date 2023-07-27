class Solution {
public:
    int longestString(int x, int y, int z) {
        int mn = min(x, y);
        if (x == y) return (x+y+z)*2;
        return z*2 + mn*4 + 2;
    }
};
/*

AA
BB BB BB BB BB BB BB BB ...
AB AB AB AB AB AB AB AB ...

BB AA BB AB
BB AB AA BB AB

BB AB AA 
*/