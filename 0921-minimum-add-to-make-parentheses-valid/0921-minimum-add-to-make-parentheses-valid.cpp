class Solution {
public:
    int minAddToMakeValid(string S) {
        int ans = 0;
        int cnt = 0;
        for(auto ch : S) {
            cnt += (ch=='('?1:-1);
            if (cnt < 0) {
                ans++;
                cnt = 0;
            }
        }
        ans += cnt;
        return ans;
    }
};