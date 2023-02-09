class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        int n = ideas.size();
        unordered_set<string> counter[26];
        for (auto &idea : ideas) {
            counter[idea[0] - 'a'].insert(idea.substr(1));
        }
        long long ans = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = i + 1; j < 26; j++) {
                long long c1 = 0, c2 = 0;
                for (auto &str : counter[i]) {
                    if (!counter[j].count(str)) c1++;
                }
                for (auto &str : counter[j]) {
                    if (!counter[i].count(str)) c2++;
                }
                ans += c1*c2;
            }
        }
        return ans*2;
    }
};