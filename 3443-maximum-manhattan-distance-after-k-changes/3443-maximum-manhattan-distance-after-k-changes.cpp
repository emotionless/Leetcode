class Solution {
public:
    int maxDistance(string str, int k) {
        int ans = 0;
        int n = 0, s = 0, w = 0, e = 0;
        int r = 0;
        for (char ch : str) {
            if (ch == 'N') n++, r++;
            else if (ch == 'W') w++, r++;
            else if (ch == 'S') s++, r--;
            else e++, r--;
            
            ans = max(ans, abs(r) + 2*min(k, min(n, s) + min(w, e)));
        }
        return ans;
    }
};