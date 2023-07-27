class Solution {
public:
    int longestString(int x, int y, int z) {
        int mn = min(x, y);
        mn = min(mn, z);
        x -= mn;
        y -= mn;
        z -= mn;
        int ans = mn*6;
        if (z == 0) return ans + ((x == y)? (x+y)*2 : (min(x, y)*4 + 2));
        return ans + ((x > 0 || y > 0)? 2 : 0) + z*2;
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