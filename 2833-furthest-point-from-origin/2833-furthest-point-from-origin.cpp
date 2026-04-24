class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        char  last = ' ';
        int point =  0;
        int ans  = 0;
        int l = 0,r = 0;
        for  (auto  ch  : moves) {
            if  (ch ==  '_') point++;
            else  if (ch == 'L') l++;
            else r++;
        }
        return max(l-r+point, r -  l + point);
    }
};