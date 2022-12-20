class Solution {
public:
    
    void dfs(int cur, const vector<vector<int>> &rooms, vector<bool> &vis) {
        vis[cur] = true;
        for (auto v : rooms[cur]) {
            if (!vis[v]) {
                dfs(v, rooms, vis);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        dfs(0, rooms, vis);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                return false;
            }
        }
        return true;
    }
};