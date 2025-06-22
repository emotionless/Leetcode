class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> count;
        for (auto ch : s) {
            count[ch]++;
        }
        int mn = s.size();
        int mx = 0;
        for (auto mp : count) {
            if (mp.second%2==0)
                mn = min(mn, mp.second);
            if (mp.second%2==1)
                mx = max(mx, mp.second);
        }
        return mx - mn;
    }
};