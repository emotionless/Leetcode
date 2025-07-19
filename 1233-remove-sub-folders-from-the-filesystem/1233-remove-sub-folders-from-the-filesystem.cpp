class Solution {
public:
    struct node {
        bool isEnd;
        node *nxt[27];
        node() {
            isEnd = false;
            for (int i = 0; i < 27; i++) {
                nxt[i] = nullptr;
            }
        }
    };
    
    bool insert(const string &str) {
        node *cur = root;
        for (auto ch : str) {
            int id = ch == '/'? 26 : (ch - 'a');
            if (cur->nxt[id] == nullptr) cur->nxt[id] = new node();
            cur = cur->nxt[id];
            if (cur -> isEnd == true) return false;
        }
        cur -> isEnd = true;
        return true;
    }
    
    struct comparator {
        bool operator()(const string &a, const string &b) {
            return a.size() < b.size();
        }
    };
    
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        root = new node();
        vector<string> files(folder.begin(), folder.end());
        sort(files.begin(), files.end(), comparator());
        for (auto file : files) {
            if (insert(file + "/")) {
                ans.push_back(file);
            }
        }
        return ans;
    }
private:
    node *root;
};