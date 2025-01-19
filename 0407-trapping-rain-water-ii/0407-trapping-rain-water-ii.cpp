class Solution {
public:
    int dr[4]= {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    
    int n, m;
    bool vis[211][211];    
    int trapRainWater(vector<vector<int>>& heightMap) {
        n = heightMap.size();
        if(n == 0) return 0;
        m = heightMap[0].size();

        memset(vis, false, sizeof vis);
        priority_queue< pair<int, pair<int, int> > > container;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 || i == (n-1) || j == 0 || j == (m-1)) {
                    vis[i][j] = true;
                    container.push(make_pair(-heightMap[i][j], make_pair(i, j)));
                }
            }
        }
        int mx = 0;
        int ans = 0;
        while(!container.empty()) {
            pair<int, pair<int, int>> top = container.top();
            container.pop();
            int x = top.second.first;
            int y = top.second.second;
            int val = top.first;
            if(!(x == 0 || y == 0 || x >= n || y >= m))
                ans += max(0, mx + val);
            mx = max(mx, -val);
            //cout<<x<<" "<<y<<" "<<val<<endl;
            for(int i = 0; i < 4; i++) {
                int ax = x + dr[i];
                int ay = y + dc[i];
                if(ax < 0 || ax >= n || ay < 0 || ay >= m || vis[ax][ay]) continue;
                container.push(make_pair(-heightMap[ax][ay], make_pair(ax, ay)));
                vis[ax][ay] = true;
            }
        }
        return ans;
    }
};