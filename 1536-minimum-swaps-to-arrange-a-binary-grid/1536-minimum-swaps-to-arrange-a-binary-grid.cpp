class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0)
                    sum += 1;
                else break;
            }
            grid[i][0] = sum;
        }
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            int j = i;
            for(j = i; j < n; j++) {
                if (grid[j][0] >= (n-i - 1)) {
                    break;
                }
            }
            if (j == n) return -1;
            ans += j - i;
            // cout << i << " " << j << endl;
            for(int k = j - 1; k >= i; k--) {
                swap(grid[k], grid[k+1]);
            }
        }
        return ans;
    }
};