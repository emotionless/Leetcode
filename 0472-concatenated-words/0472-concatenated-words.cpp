class Solution {
public:
    
    struct Node {
        Node* next[26];
        bool is;
        Node() {
            is = false;
            for(int i = 0; i < 26; i++) next[i] = nullptr;
        }
    };
    
    void insert(Node *root, const string str) {
        Node *cur = root;
        for(int i = 0; i < str.length(); i++) {
            int id = str[i] - 'a';
            if (cur -> next[id] == nullptr) {
                cur -> next[id] = new Node();
            }
            cur = cur -> next[id];
        }
        cur -> is = true;
        
    }
    
    bool solve(int ind, const string &str, const Node *cur) {
        if (ind >= str.length()) {
            return true;
        }
        int &ret = dp[ind];
        if (ret != -1) return ret;
        ret = 0;
        string tmp = "";
        for(int i = ind; i < str.length(); i++) {
            int id = str[i] - 'a';
            if (cur -> next[id] == nullptr) break;
            cur = cur -> next[id];
            if (cur -> is) {
                ret = ret | solve(i+1, str, root);
                if (ret) break;
            }
        }
        return ret;
    }
    
    vector<string> findAllConcatenatedWordsInADict(const vector<string>& words) {
        vector<pair<int, string>> container;
        for(auto word : words) {
            if (word.size())
                container.push_back(make_pair(word.length(), word));
        }
        vector<string> ans;
        sort(container.begin(), container.end());
        root = new Node();
        for(auto v : container) {
            dp.clear();
            dp.resize(v.second.size(), -1);
            if (solve(0, v.second, root)) {
                ans.push_back(v.second);
            } else {
                insert(root, v.second);
                // vis[v.second] = true;
            }
        }
        return ans;
    }
private:
    unordered_map<string, int> vis;
    vector<int> dp;
    Node *root;
};