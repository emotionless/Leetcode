class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long res = total / cost2 + 1;
        for (int i = cost1; i <= total; i += cost1) {
            int now = (total - i) / cost2;
            res += now + 1;
        }
        return res;
    }
};