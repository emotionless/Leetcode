class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> counter;
        int len = s.length();
        int j = 0;
        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            j = max(i, j);
            while (j < len && cnt != 3) {
                counter[s[j]]++;
                if (counter[s[j]] == 1) cnt++;
                j++;
            }
            if (cnt == 3) {
                ans += (len - j + 1);
            }
            counter[s[i]]--;
            if (counter[s[i]] == 0) cnt--;
        }
        return ans;
    }
};