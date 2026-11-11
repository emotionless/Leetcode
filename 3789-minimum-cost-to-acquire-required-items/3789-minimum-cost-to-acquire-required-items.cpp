class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 0;
        if (costBoth  < cost1) cost1 = costBoth;
        if (costBoth  < cost2) cost2 = costBoth;

        if (cost1 + cost2 < costBoth) return need1 * 1LL * cost1 + need2 * 1LL * cost2;
        long long need = min(need1, need2);
        return  need * costBoth + (need1 - need) * cost1 + (need2 - need) * cost2; 
    }
};