class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> counter;
        for (auto ch : s) {
            counter[ch]++;
        }
        for (auto ch : t) {
            counter[ch]--;
        }
        int ans = 0;
        for (auto item : counter) {
            ans += abs(item.second);
        }
        return ans;
    }
};