class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        
        vector<int> ans;
        int cnt[n + 1][26];
        int tar[26];
        memset(cnt, 0, sizeof cnt);
        memset(tar, 0, sizeof tar);
        int plen = p.length();
        
        for(int i = 0; i < plen; i++) {
            tar[ p[i] - 'a' ]++;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 26; j++) {
                if (i)
                    cnt[i][j] = cnt[i-1][j];
            }
            cnt[i][s[i] - 'a']++;
            if (i < (plen-1)) continue;
            bool ck = false;
            for(int j = 0; j < 26; j++) {
                int have = cnt[i][j] - ((i-plen)>=0?cnt[i-plen][j] : 0);
                if (have != tar[j]) { ck = true; break; }
            }
            if (ck == false) ans.push_back(i-plen + 1);
        }
        return ans;
    }
};