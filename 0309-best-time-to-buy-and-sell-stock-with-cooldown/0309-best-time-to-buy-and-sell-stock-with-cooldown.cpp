class Solution {
public:
    
    int getMaxProfit(int ind, bool isBought, const vector<int> &prices) {
        if (ind >= prices.size()) return 0;
        int &ret = dp[ind][isBought];
        if (ret != -1) return ret;
        ret = 0;
        ret = getMaxProfit(ind + 1, isBought, prices);
        if (isBought)
            ret = max(ret, prices[ind] + getMaxProfit(ind + 2, 1 - isBought, prices));
        else
            ret = max(ret, -prices[ind] + getMaxProfit(ind + 1, 1 - isBought, prices));
        
        return ret;
    }
    
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(), vector<int>(2, -1));
        return getMaxProfit(0, 0, prices);
    }
private:
    vector<vector<int>> dp;
};