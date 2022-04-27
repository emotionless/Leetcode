class Solution {
public:
    
    void dfs(int ind, set<int> &indices, multiset<char> &letters, string &s) {
        indices.insert(ind);
        letters.insert(s[ind]);
        
        visited[ind] = true;
        for (auto &v : adj[ind]) {
            if (!visited[v]) {
                dfs(v, indices, letters, s);
            }
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        adj.resize(n);
        for (auto &v : pairs) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        visited.resize(n, false);
        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {
                set<int> indices;
                multiset<char> letters;

                dfs(i, indices, letters, s);
                auto it = letters.begin();
                for (auto now : indices) {
                    s[now] = *it;
                    it++;
                }
            }
        }
        return s;
    }
private:
    vector<vector<int>> adj;
    vector<bool> visited;
};