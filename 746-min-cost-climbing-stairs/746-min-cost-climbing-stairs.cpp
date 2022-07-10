class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a = 0, b = 0;
        for (int i = cost.size() - 1; i >= 0; i--) {
            int mn = min(a, b);
            b = a;
            a = mn + cost[i];
        }
        return min(a, b);
    }
};