class Solution {
public:
    bool is[3][3][10];
    vector<int> freedContainer[3][3];
    bool vis[3][3][10];
    
    bool equal(const char a, const int b) {
        if (a == '.') return false;
        return (a-'0') == b;
    }
    
    bool check(const vector<vector<char>> &board, const int x, const int y, const int d) {
        for(int j = 0; j < 9; j++) {
            if (equal(board[x][j], d)) return false;
        }
        for(int i = 0; i < 9; i++) {
            if (equal(board[i][y], d)) return false;
        }
        return true;
    }
    
    bool solve(int i, int j, vector<vector<char>> &board) {
        if (i == 9) {
            return true;
        }
        if (j == 9) return solve(i + 1, 0, board);
        else if (board[i][j] != '.') {
            return solve(i, j + 1, board);
        }
        // cout << i << " " << j << endl;
        for(auto k : freedContainer[i/3][j/3]) {
            if (!vis[i/3][j/3][k] && check(board, i, j, k)) {
                vis[i/3][j/3][k] = true;
                board[i][j] = (char)(k + '0');
                if (solve(i, j+1, board))
                    return true;
                board[i][j] = '.';
                vis[i/3][j/3][k] = false;
            }
        }
        return false;
    }
    
    
    void solveSudoku(vector<vector<char>>& board) {
        memset(is, false, sizeof is);
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if (board[i][j] != '.')
                    is[i/3][j/3][board[i][j] - '0'] = true;
            }
        }
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                int k = 1;
                // cout << i << " " << j << endl;
                while(k < 10) {
                    if (is[i][j][k] == false) {
                        freedContainer[i][j].push_back(k);
                        // cout << k << endl;
                    }
                    k++;
                }
            }
        }
        solve(0, 0, board);
        return;
    }
};