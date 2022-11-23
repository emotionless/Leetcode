class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        int m = 9;
        bool isContain[2][9][10];
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 10; j++) {
                isContain[0][i][j] = isContain[1][i][j] = false;
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                char cur = board[i][j];
                if(cur == '.') continue;
                if(isContain[0][i][cur-'0']) return false;
                if(isContain[1][j][cur-'0']) return false;
                isContain[0][i][cur-'0'] = isContain[1][j][cur-'0'] = true;
            }
        }
        // for 3*3
        
        for(int i = 0; i < n; i += 3) {
            for(int j = 0; j < m; j += 3) {
                
                bool vis[10] = {false};
                
                for(int k = i; k < (i+3); k++) {
                    for(int l = j; l < (j+3); l++) {
                        char cur = board[k][l];
                        if(cur == '.') continue;
                        if(vis[cur-'0']) return false;
                        vis[cur-'0'] = true;
                    }
                }
            }
        }
        return true;
    }
};