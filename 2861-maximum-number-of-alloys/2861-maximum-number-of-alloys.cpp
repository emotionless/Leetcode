class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& compositions, vector<int>& stock, vector<int>& cost) {
        int res = 0;
        for (auto &composition : compositions) {
            res = max(res, maxAlloy(composition, budget, stock, cost));
        }
        return res;
    }
private:
    int maxAlloy(vector<int> &composition, int budget, vector<int> &stock, vector<int> &cost) {
        int n = composition.size();
        int st = 0, ed = 1000000000;
        int ans = 0;
        while (st <= ed) {
            int mid = (st + ed) / 2;
            long long need = 0ll;
            int i = 0;
            for (auto &num : composition) {
                long long totalNeed = 1ll * num * mid;
                need += max(0ll, totalNeed - stock[i]) * cost[i];
                i++;
            }
            if (need <= budget) {
                ans = mid;
                st = mid + 1;
            } else {
                ed = mid - 1;
            }
        }
        return ans;
    }
};