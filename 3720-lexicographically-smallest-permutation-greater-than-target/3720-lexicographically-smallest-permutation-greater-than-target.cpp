class Solution {
public:
    char getsmallest(unordered_map<char, int> &counter, char ch) {
        for (char c = ch; c <= 'z'; c++) {
            if (counter[c] > 0) {
                counter[c]--;
                return c;
            }
        }
        return '0';
    }
    string lexGreaterPermutation(string str, string target) {
        unordered_map<char, int> counter;
        for (auto ch : str) {
            counter[ch]++;
        }
        string ans = "";
        for (auto ch : target) {
            char s = getsmallest(counter, ch);
            if (s == '0') break;
            ans += s;
            if (s > ch) break;
        }
        string sub = target;

        // cout << ans << " " << sub << endl;
        // return sub;
        if (ans <= sub) {
            int i = 0;
            for (i = ans.size() - 1; i >= 0; i--) {
                char ch = getsmallest(counter, ans[i] + 1);
                if (ch == '0') {
                    counter[ans[i]]++;
                } else {
                    counter[ans[i]]++;
                    ans[i] = ch;
                    break;
                }
            }
            ans.resize(i+1);
        }
        if (ans.size() == 0) return "";
        // cout  << ans << endl;

        for (char c = 'a'; c <= 'z'; c++) {
            while (counter[c] > 0) {
                counter[c]--;
                ans += c;
            }
        }
        return ans;

    }
};