class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int ans = 0;
        int sum = 0;
        int tot = 0;
        for (int i = 0; i < n; i++) {
            sum += gas[i] - cost[i];
            tot += gas[i] - cost[i];
            if (sum < 0) {
                ans = i + 1;
                sum = 0;
            }
        }
        if (tot < 0) return -1;
        return ans;
    }
};