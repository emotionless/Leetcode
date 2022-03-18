class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        int cnt = 0;
        for (auto ch : s) {
            cnt += (letter == ch? 1 : 0);
        }
        int len = s.size();
        string container;
        for (int i = 0; i < len; i++) {
            while (container.size() && container.back() > s[i]) {     // May remove
                if ((container.size() + (len - i)) > k) {
                    if (container.back() == letter) {
                        if (cnt > repetition) {
                            cnt--;
                            container.pop_back();
                        } else break;
                    } else {
                        container.pop_back();
                    }
                } else break;
            }
            container.push_back(s[i]);
        }
        string ans = "";
        for (int i = 0; ans.size() < k; i++) {
            if (container[i] != letter && (ans.size() + max(0, repetition) >= k)) {
                continue;
            }
            repetition -= (container[i] == letter);
            ans += container[i];
        }
        return ans;
    }
};
