class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    
    struct Node {
        bool is, vis;
        Node *next[26];
        Node() {
            is = false;
            vis = false;
            for(int i = 0; i < 26; i++) {
                next[i] = nullptr;
            }
        }
    };
    
    void insert(Node *cur, const string str) {
        for(int i = 0; i < str.length(); i++) {
            int id = str[i] - 'a';
            if (cur -> next[id] == nullptr) {
                cur -> next[id] = new Node();
            }
            cur = cur -> next[id];
        }
        cur -> is = true;
    }
    
    void dfs(int x, int y, Node *cur, const vector<vector<char>> &board) {
        int id = board[x][y] - 'a';
        if (cur -> next[id] == nullptr) return;
        cur = cur -> next[id];
        if (cur == nullptr) return;
        
        if (cur -> is) {
            cur -> vis = true;
        }
        for(int i = 0; i < 4; i++) {
            int ax = x + dr[i];
            int ay = y + dc[i];
            if (ax < 0 || ax >= n || ay < 0 || ay >= m || vis[ax][ay]) continue;
            vis[ax][ay] = true;
            dfs(ax, ay, cur, board);
            vis[ax][ay] = false;
        }
        return;
    }
    
    void traverse(Node *cur, const string str, vector<string> &ans) {
        if (cur == nullptr) {
            return;
        }
        if (cur -> is) {
            if (cur -> vis == false) return;
            ans.push_back(str);
        }
        for(int i = 0; i < 26; i++) {
            traverse(cur->next[i], str + (char)(i+'a'), ans);
        }
        
        return;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node *root = new Node();
        
        for(auto word : words) {
            insert(root, word);
        }
        n = board.size();
        if (n == 0) return {};
        m = board[0].size();
        vis.resize(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                vis[i][j] = true;
                // cout << "New " << endl;
                dfs(i, j, root, board);
                vis[i][j] = false;
            }
        }
        vector<string> ans;
        traverse(root, "", ans);
        
        return ans;
    }
private:
    int n, m;
    vector<vector<bool>> vis;
};