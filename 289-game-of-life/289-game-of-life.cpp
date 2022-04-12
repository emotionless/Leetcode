class Solution {
public:
    
    int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    
    int getCount(int c, vector<vector<int>> &matrix) {
        int x = 1, y = c;
        int cnt = 0;
        for (int i = 0; i < 8; i++) {
            int ax = x + dr[i];
            int ay = y + dc[i];
            if (ay < 0 || ay >= matrix[1].size()) continue;
            cnt += matrix[ax][ay];
        }
        return cnt;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> matrix;
        int m = board[0].size();
        matrix.resize(3, vector<int>(board[0].size(), 0));
        matrix[2] = board[0];
        for (int i = 0; i < board.size(); i++) {
            matrix[0] = matrix[1];
            matrix[1] = matrix[2];
            if ((i+1) < board.size()) {
                matrix[2] = board[i+1];
            } else {
                matrix[2] = vector<int>(m, 0);
            }
            
            for (int j = 0; j < m; j++) {
                int cnt = getCount(j, matrix);
                if (cnt < 2 || cnt > 3) {
                    board[i][j] = 0;
                } else if (cnt == 3) board[i][j] = 1;
            }
        }
    }
};