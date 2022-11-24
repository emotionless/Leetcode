class Solution {
public:
    const int dr[4] = {-1, 0, 1, 0};
    const int dc[4] = {0, 1, 0, -1};
    
    bool dfs(int i, int j, int pos, const vector<vector<char>> &board, const string &word) {
        if ((pos-1) == (word.size() - 1)) return true;
        visited[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int ai = i + dr[k];
            int aj = j + dc[k];
            if (ai < 0 || ai >= n || aj < 0 || aj >= m || visited[ai][aj]) continue;
            if (board[ai][aj] != word[pos]) continue;
            if (dfs(ai, aj, pos + 1, board, word)) return true;
        }
        visited[i][j] = false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string &word) {
        n = board.size();
        m = board[0].size();
        visited.resize(n, vector<bool>(m, false));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (word[0] == board[i][j]) {
                    if (dfs(i, j, 1, board, word)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
private:
    vector<vector<bool>> visited;
    int n, m;
};