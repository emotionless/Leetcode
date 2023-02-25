class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int mn = prices[0];
        for (auto price : prices) {
            ans = max(ans, price - mn);
            mn = min(mn, price);
        }
        return ans;
    }
};