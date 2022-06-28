class Solution {
public:
    int minDeletions(string s) {
        int freq[26] = {0};
        for(auto ch : s) {
            freq[ch-'a']++;
        }
        int ans = 0;
        unordered_map<int, bool> vis;
        for(int i = 0; i < 26; i++) {
            for(int j = freq[i]; j > 0; j--) {
                if(vis.find(j) == vis.end()) {
                    vis[j] = true;
                    break;
                } else {
                    ans++;
                }
            }
        }
        return ans;
    }
};