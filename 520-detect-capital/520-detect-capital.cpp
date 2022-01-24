class Solution {
public:
    bool detectCapitalUse(string word) {
        int len = word.size();
        int upper = 0;
        for (auto ch : word) {
            if (isupper(ch)) upper++;
        }
        return len == upper || upper == 0 || (upper == 1 && isupper(word[0]));
    }
};