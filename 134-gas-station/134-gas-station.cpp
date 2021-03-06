class Solution {
public:
    int canCompleteCircuit(const vector<int>& gas, const vector<int>& cost) {
        int n = gas.size();
        int ans = 0;
        int sum = 0;
        int tot = 0, dif = 0;
        for (int i = 0; i < n; i++) {
            dif = gas[i] - cost[i];
            sum += dif;
            tot += dif;
            if (sum < 0) {
                ans = i + 1;
                sum = 0;
            }
        }
        if (tot < 0) return -1;
        return ans;
    }
};