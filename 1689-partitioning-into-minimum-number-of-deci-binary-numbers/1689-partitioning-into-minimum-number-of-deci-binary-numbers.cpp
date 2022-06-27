class Solution {
public:
    int minPartitions(string n) {
        char mx = '0';
        for (auto ch : n) {
            mx = max(mx, ch);
        }
        return mx - '0';
    }
};