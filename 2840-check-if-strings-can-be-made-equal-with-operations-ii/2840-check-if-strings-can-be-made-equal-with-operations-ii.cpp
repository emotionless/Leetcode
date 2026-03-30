class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char, int> even, odd;
        for (int i = 0; i < s1.size(); i++) {
            if (i%2 == 0) even[s1[i]]++, even[s2[i]]--;
            else odd[s1[i]]++, odd[s2[i]]--;
        }
        for (auto ch : even) {
            if (ch.second != 0) return false;
        }

        for (auto ch : odd) {
            if (ch.second != 0) return false;
        }
        return true;
    }
};