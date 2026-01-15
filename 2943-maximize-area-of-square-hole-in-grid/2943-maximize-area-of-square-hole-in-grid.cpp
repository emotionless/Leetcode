class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int pre = -1;
        int cnt = 1;
        int mx = 0;
        for (auto v : hBars)  {
            if (v == pre + 1)  cnt++;
            else cnt = 1;
            pre = v;
            mx = max(mx, cnt);
        }
        int mx1 = 0;
        cnt = 1;

        for (auto v : vBars)  {
            if (v == pre + 1)  cnt++;
            else cnt = 1;
            pre = v;
            mx1 = max(mx1, cnt);
        }
        int mn = min(mx + 1, mx1 + 1);
        return mn * mn;
    }
};