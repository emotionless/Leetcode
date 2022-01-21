class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int ans = 0;
        int sum = 0;
        int tot = 0;
        for (int i = 0; i < n; i++) {
            int dif = gas[i] - cost[i];
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