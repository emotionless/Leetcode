class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int i = x; i < (x + k/2);  i++) {
            for (int j = y; j < (y + k); j++) {
                int ni = x+k-1-(i-x);
                // cout << i << " " << ni <<  endl;
                swap(grid[i][j], grid[ni][j]);
            }
        }
        return grid;
    }
};