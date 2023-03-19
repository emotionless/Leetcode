class WordDictionary {
public:
    
    struct ListNode {
        bool isEnd;
        ListNode *next[26];
        ListNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++) {
                next[i] = nullptr;
            }
        }
    };
    
    
    WordDictionary() {
        root = new ListNode();
    }
    
    void addWord(string word) {
        ListNode *cur = root;
        for (auto ch : word) {
            int id = ch - 'a';
            if (cur->next[id] == nullptr) cur->next[id] = new ListNode();
            cur = cur->next[id];
        }
        cur->isEnd = true;
    }
    
    bool search(int ind, string &word, ListNode *cur) {
        if (cur == nullptr) return false;
        if (ind == word.size()) {
            return cur->isEnd;
        }
        int id = word[ind] - 'a';
        int ret = 0;
        if (word[ind] == '.') {
            for (int i = 0; i < 26; i++) {
                ret += search(ind + 1, word, cur->next[i]);
                if (ret) return ret;
            }
        } else {
            ret = search(ind + 1, word, cur->next[id]);
        }
        return ret;
    }
    
    bool search(string word) {
        return search(0, word, root);
    }
private:
    ListNode *root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */