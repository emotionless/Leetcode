class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int tot = 0;
        int pre = 0;
        for (auto row : bank) {
            int sum = 0;
            for (auto ch : row) {
                sum += ch - '0';
            }
            if (sum > 0) {
                tot += sum * pre;
                pre = sum;
            }
        }
        return tot;
    }
};