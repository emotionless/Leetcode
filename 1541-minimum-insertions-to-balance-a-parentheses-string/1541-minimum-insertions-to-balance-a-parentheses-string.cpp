class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int len = s.length();
        int sum = 0;
        for (int i = 0; i < len; i++) {
            int j = i;
            while (j < len && s[j] == s[i]) {
                sum += s[j] == ')'? -1 : 2;
                j++;
            }
            if (sum < 0) {
                ans += (-sum + 1)/2;
                ans += (-sum)% 2;
                sum = 0;
            } else if (sum&1) {
                sum--;
                ans++;
            }
            i = j - 1;
        }
        ans += sum;
        return ans;
    }
};