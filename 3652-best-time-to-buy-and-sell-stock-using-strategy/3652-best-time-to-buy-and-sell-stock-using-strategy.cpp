class Solution {
public:
    

    long long getTotal(vector<long long> &prices, int i, int j) {
        if (i == 0) return prices[j];
        return prices[j] - prices[i-1];
    }
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> sum (n, 0), all(n, 0);
        sum[0] = prices[0] * strategy[0];
        all[0] = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            sum[i] = sum[i-1] + prices[i] * strategy[i];
            all[i] = all[i-1] + prices[i];
        }
        int half = k / 2;
        long long ans = sum[n-1];
        for (int i = k-1; i < n; i++) {
            long long total = sum[n-1];
            int st = i - k + 1;
            int mid = st + half - 1;
            int ed = i;
            total -= getTotal(sum, st, ed);
            total += getTotal(all, mid + 1, ed);
            ans = max(ans, total);
        }
        return ans;
        
    }
};