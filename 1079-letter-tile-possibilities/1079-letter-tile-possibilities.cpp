class Solution {
public:
    
    void solve(int mask, int n, string &str, string &tiles) {
        if (container.find(str) == container.end()) 
            container.insert(str);
        else
            return;
        
        for (int i = 0; i < n; i++) {
            if (!(mask&(1<<i))) {
                str += tiles[i];
                solve(mask|(1<<i), n, str, tiles);
                str.pop_back();
            }
        }
        return;
    }
    
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        string str = "";
        solve(0, n, str, tiles);
        return container.size() - 1;
    }
private:
    unordered_set<string> container;
};