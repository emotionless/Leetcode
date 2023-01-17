class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int total = 0;
        for (auto ch : s) {
            total += ch - '0';
        }
        int zero = 0;
        int answer = min(total, (int)s.size() - total);
        for (int i = s.size() - 1; i >= 0; i--) {
            total -= (s[i] - '0');
            if (s[i] == '0') zero++;
            answer = min(answer, total + zero);
        }
        return answer;
    }
};