class Solution {
public:
    int bestClosingTime(string customers) {
        int y = 0;
        for (auto ch : customers) {
            y += (ch == 'Y'? 1 : 0);
        }
        int n = 0;
        int len = customers.size();
        int ans = INT_MAX;
        int pos = 0;
        for (int i = 0; i < len; i++) {
            int penalty = y + n;
            if (penalty < ans) {
                ans = penalty;
                pos = i;
            }
            n += (customers[i] == 'N'? 1 : 0);
            y -= (customers[i] == 'Y'? 1 : 0);
        }
        if ((n + y) < ans) pos = len;
        return pos;
    }
};