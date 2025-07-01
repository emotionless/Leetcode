class Solution {
public:
    int possibleStringCount(string word) {
        int len = word.size();
        int cnt = 1;
        for (int i = 1; i < len; i++) {
            if (word[i] != word[i-1]) {
                cnt++;
            }
        }
        return len - cnt + 1;
    }
};