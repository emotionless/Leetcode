class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int mx = 0;
        int  sum  = 0;
        for  (auto num :  gain) {
            sum += num;
            mx = max(mx, sum);
        }
        return mx;
    }
};