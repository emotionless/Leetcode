class Solution {
public:
    
    void solve(int mask, int n, string str, string &tiles) {
        container.insert(str);
        for (int i = 0; i < n; i++) {
            if (!(mask&(1<<i))) {
                solve(mask|(1<<i), n, str + tiles[i], tiles);
            }
        }
        return;
    }
    
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        solve(0, n, "", tiles);
        return container.size() - 1;
    }
private:
    unordered_set<string> container;
};