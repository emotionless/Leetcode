class MapSum {
public:
    
    struct node {
        int val;
        node *next[26];
        node() {
            val = 0;
            for (int i = 0; i < 26; i++) {
                next[i] = nullptr;
            }
        }
    };
    
    MapSum() {
        root = new node();
    }
    
    void insert(string key, int val) {
        if (prev[key] != 0) {
            int v = prev[key];
            prev[key] = 0;
            insert(key, -v);
        }
        node *cur = root;
        for (auto ch : key) {
            int id = ch - 'a';
            if (cur->next[id] == nullptr) {
                cur->next[id] = new node();
            }
            cur = cur->next[id];
            cur->val += val;
        }
        prev[key] = val;
    }
    
    int sum(string prefix) {
        node *cur = root;
        for (auto ch : prefix) {
            int id = ch - 'a';
            if (cur->next[id] == nullptr) {
                cur->next[id] = new node();
            }
            cur = cur->next[id];
        }
        return cur->val;
    }
private:
    node *root;
    unordered_map<string, int> prev;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */