class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long res = 0;
        for (int i = 0; i <= total; i += cost1) {
            res += (total - i) / cost2 + 1;
        }
        return res;
    }
};