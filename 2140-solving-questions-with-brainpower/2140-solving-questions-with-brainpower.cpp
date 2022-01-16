class Solution {
public:
    
    long long solve(int ind, const vector<vector<int>> &questions) {
        if (ind >= questions.size()) {
            return 0;
        }
        long long &ret = dp[ind];
        if (ret != -1) return ret;
        ret = 0;
        ret = questions[ind][0] + solve(ind + questions[ind][1] + 1, questions);
        ret = max(ret, solve(ind + 1, questions));
        
        return ret;
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        dp.resize(n, -1);
        return solve(0, questions);
    }
private:
    vector<long long> dp;
};