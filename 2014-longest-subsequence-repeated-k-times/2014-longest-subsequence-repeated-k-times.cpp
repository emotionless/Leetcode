class Solution {

private:
    bool maintainSubseq(const string &s, const string &subseq, const int &K) {
        int len = s.size();
        int sLen = subseq.size();
        int ind = 0;
        int total = 0;
        for (auto ch : s) {
            if (ch == subseq[ind]) {
                ind++;
                if (ind == sLen) {
                    total++;
                    ind = 0;
                }
            }
        }
        return total >= K;
    }

public:
    string longestSubsequenceRepeatedK(string s, int k) {
        int len = s.size();
        unordered_map<char, int> freq;
        for (auto ch : s) {
            freq[ch]++;
        }
        queue<string> q;
        vector<char> candidates;
        for (char ch = 'z'; ch >= 'a'; ch--) {
            if (freq[ch] >= k) {
                candidates.push_back(ch);
                q.push(string(1, ch));
            }
        }
        string ans = "";
        while (!q.empty()) {
            string top = q.front();
            q.pop();
            if (top.size() > ans.size()) {
                ans = top;
            }
            for (auto ch : candidates) {
                string next = top + ch;
                if (maintainSubseq(s, next, k)) {
                    q.push(next);
                }
            }
        }
        return ans;
    }
};