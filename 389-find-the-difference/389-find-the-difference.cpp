class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum = 0;
        for (auto &ch : s) {
            sum ^= ch;
        }
        for (auto &ch : t) {
            sum ^= ch;
        }
        return (char) sum;
    }
};