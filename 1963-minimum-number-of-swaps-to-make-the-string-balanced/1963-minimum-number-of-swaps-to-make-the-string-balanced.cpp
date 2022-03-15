class Solution {
public:
    int minSwaps(string &s) {
        int cnt = 0;
        int ans = 0;
        
        for (auto &ch : s) {
            cnt += (ch == '['? 1 : -1);
            if (cnt < 0) {
                ans++;
                cnt = 0;
            }
        }
        ans += cnt;
        return (ans/2 + 1)/2;
    }
};