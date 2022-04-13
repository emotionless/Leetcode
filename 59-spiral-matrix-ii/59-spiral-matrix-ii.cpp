int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

class Solution {
public:
    int n, m;
    void DFS(int x, int y, int d, vector<vector<int>> &ans, int &ind)
    {
        if(ans[x][y] != -1) return;
        ans[x][y] = (++ind);
        for(int i = d; i < 8; i++)
        {
            int j = i%4;
            int adjx = dr[j] + x;
            int adjy = dc[j] + y;
            if(adjx < 0 || adjx >= n || adjy < 0 || adjy >= n || ans[adjx][adjy] != -1) continue;
            DFS(adjx, adjy, j, ans, ind);
            return;
        }
        return;
    }
    
    vector<vector<int>> generateMatrix(int nn) {
        int ind = 0;
        n = nn;
        if(!n) return {};
        m = n;
        vector<vector<int>> ans;
        ans.resize(n, vector<int>(n, -1));
        DFS(0, 0, 0, ans, ind);
        return ans;
    }
};