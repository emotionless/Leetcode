class Solution {
public:
    
    void dfs(int ind, vector<int> &indices, vector<char> &letters, string &s) {
        indices.push_back(ind);
        letters.push_back(s[ind]);
        
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
                vector<int> indices;
                vector<char> letters;

                dfs(i, indices, letters, s);
                sort(indices.begin(), indices.end());
                sort(letters.begin(), letters.end());
                int sz = indices.size();
                for(int i = 0; i < sz; i++) {
                    s[indices[i]] = letters[i];
                }
            }
        }
        return s;
    }
private:
    vector<vector<int>> adj;
    vector<bool> visited;
};