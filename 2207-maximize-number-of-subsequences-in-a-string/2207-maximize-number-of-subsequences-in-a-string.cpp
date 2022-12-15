class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        int a = 0, b = 0;
        long long ans = 0;
        int len = text.size();
        for (int i = 0; i < len; i++) {
            if (text[i] == pattern[1]) {
                b++;
                ans += a;
            }
            if (text[i] == pattern[0]) a++;
            
        }
        ans += max(a, b);
        return ans;
    }
};