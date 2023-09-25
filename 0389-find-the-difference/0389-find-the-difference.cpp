class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum = 0;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            sum ^= s[i];
            sum ^= t[i];
        }
        sum ^= t[len];
        return (char) sum;
    }
};