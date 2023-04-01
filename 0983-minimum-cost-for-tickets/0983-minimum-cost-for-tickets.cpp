class Solution {
public:
    
    int getInd(int ind, vector<int> &days, int mx) {
        while (ind < days.size() && days[ind] <= mx) ind++;
        return ind;
    }
    
    int solve(int ind, vector<int> &days, vector<int> &costs) {
        if (ind == days.size()) return 0;
        int &ret = dp[ind];
        if (ret != -1) return ret;
        ret = INT_MAX;
        ret = min(ret, costs[0] + solve(ind + 1, days, costs));
        int nxt = getInd(ind, days, days[ind] + 6);
        ret = min(ret, costs[1] + solve(nxt, days, costs));
        nxt = getInd(ind, days, days[ind] + 29);
        ret = min(ret, costs[2] + solve(nxt, days, costs));
        
        return ret;
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        dp.resize(n, -1);
        return solve(0, days, costs);
    }
private:
    vector<int> dp;
};