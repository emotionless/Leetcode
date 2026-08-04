class Solution {
public:
    
    // int solve(int ind, bool is, const vector<int> &stones) {
    //     if (ind == stones.size()) return 0;
    //     int &ret = dp[ind][is];
    //     if (ret != -1000000000) return ret;
    //     ret = is? INF:-INF;
    //     if (is == false) {
    //         int sum = 0;
    //         for(int i = ind; i < (ind + 3) && i < n; i++) {
    //             sum += stones[i];
    //             ret = max(ret, sum + solve(i+1, 1 - is, stones));
    //         }
    //     } else {
    //         int sum = 0;
    //         for(int i = ind; i < (ind + 3) && i < n; i++) {
    //             sum += stones[i];
    //             ret = min(ret, - sum + solve(i+1, 1 - is, stones));
    //         }
    //     }
    //     // cout << ind << " " << is << " " << ret << endl;
    //     return ret;
    // }
    
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        dp.resize(n+1, -INF);
        dp[n] = 0;
        
        for(int i = n-1; i >= 0; i--) {
            int sum = 0;
            for(int j = 0; (i+j) < n && j < 3; j++) {
                sum += stoneValue[i+j];
                dp[i] = max(dp[i], sum - dp[i+j+1]);
            }
        }
        int ans = dp[0];
        if (ans == 0) return "Tie";
        else if (ans > 0) return "Alice";
        else {
            return "Bob";
        }
    }
    
private:
    vector<int> dp;
    const int INF = 100000000;
    int n;
};