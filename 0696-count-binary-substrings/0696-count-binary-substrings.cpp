class Solution {
public:
    int countBinarySubstrings(string s) {
        int i, j, k;
        int len = s.length();
        if(!len) return 1;
        int cnt[50];
        cnt['0'] = cnt['1'] = 0;
        cnt[s[0]]++;
        int ans = 0;
        int pre = 0;
        for(i = 1; i < len; i++){
            if(s[i] != s[i-1])
            {
                pre = cnt[ s[i-1] ];
                cnt['0'] = cnt['1'] = 0;
            }
            cnt[ s[i] ]++;
            int rest = (s[i]+1) % 49;
            if(cnt[ s[i] ] <= pre)
                ans++;
        }
        return ans;
    }
};