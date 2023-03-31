class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        n = pizza.size();
        m = pizza[0].size();
        dp.resize(n, vector<vector<int>>(m, vector<int>(k+1, -1)));
        mat.resize(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                mat[i][j] = (pizza[i][j] == 'A'? 1 : 0) + (i?mat[i-1][j]:0) + (j?mat[i][j-1]:0) - (i && j?mat[i-1][j-1]:0);
                // cout << mat[i][j]<< " ";
            }
            // cout << endl;
        }
        return solve(0, 0, k);
    }
private:
    vector<vector<vector<int>>> dp;
    vector<vector<int>> mat;
    int n, m;
    const int MOD = 1000000007;
    
    int solve(int r, int c, int k) {
        if (r >= n || c >= m) return 0;
        if (k == 1) {
            if (subSum(r, n-1, c, m-1)) return 1;
            return 0;
        }
        int &ret = dp[r][c][k];
        if (ret != -1) return ret;
        ret = 0;
        for(int i = r; i < n; i++) {
            if (subSum(r, i, c, m-1) > 0)
                ret = (ret + solve(i+1, c, k-1)) % MOD;
        }
        for(int i = c; i < m; i++) {
            if (subSum(r, n-1, c, i) > 0)
                ret = (ret + solve(r, i + 1, k-1)) % MOD;
        }
        // cout << r << " " << c << " " << k << " " << ret << endl; 
        return ret;
    }
    
    int subSum(int x1, int x2, int y1, int y2) {
        return mat[x2][y2] - (y1>0?mat[x2][y1-1]:0) - (x1 > 0?mat[x1-1][y2]:0) + ((x1 > 0 && y1 > 0)?mat[x1-1][y1-1]:0);
    }
    
};