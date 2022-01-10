class Solution {
public:
    
    struct node {
        bool isEnd;
        node *next[26];
        
        node() {
            isEnd = false;
            for (int i = 0; i < 26; i++) {
                next[i] = nullptr;
            }
        }
    };
    
    void insert(const string &word, node *root) {
        node *cur = root;
        for (auto ch : word) {
            int id = ch - 'a';
            if (cur->next[id] == nullptr) {
                cur->next[id] = new node();
            }
            cur = cur->next[id];
        }
        cur->isEnd = true;
    }
    
    bool possible(const string &word, node *root) {
        node *cur = root;
        for (auto ch : word) {
            int id = ch - 'a';
            if (cur->next[id] == nullptr) {
                return false;
            }
            cur = cur->next[id];
        }
        return cur->isEnd;
    }
    
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        node *root = new node();
        for (auto &word : startWords) {
            sort(word.begin(), word.end());
            insert(word, root);
        }
        int ans = 0;
        for (auto word : targetWords) {
            sort(word.begin(), word.end());
            for (int i = 0; i < word.size(); i++) {
                string str = word.substr(0, i) + word.substr(i + 1);
                if (possible(str, root)) {
                    ans += 1;
                    break;
                }
            }
        }
        return ans;
    }
};