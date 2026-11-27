class Solution {
public:
    int solve(int ind, int budget, vector<int> &store, vector<vector<int>> &items, vector<vector<int>> &dp) {
        if (ind == items.size())  {
            return budget/mn;
        }
        int &ret = dp[ind][budget];
        if  (ret != -1) return ret;
        ret = 0;
        ret = solve(ind + 1, budget, store, items, dp);
        if (items[ind][1] <= budget)
            ret = max(ret, store[ind] + solve(ind + 1, budget - items[ind][1], store, items, dp));

        return ret;
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        mn = 1501;
        for(auto item : items) {
            mn = min(item[1],mn);
        }
        vector<int>store(n,0);
        for(int i = 0; i  < n;i++) {
            int cnt =  0;
            for (int j = 0;j < n;  j++)  {
                if  (items[j][0] % items[i][0] == 0){
                    cnt++;
                }
            }
            store[i] = cnt;
        }
        vector<vector<int>> dp(n,  vector<int>(1501, -1));
        return solve(0, budget, store, items, dp);
    }
private:
    int mn = 1501;

};