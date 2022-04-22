class MyHashMap {
public:
    MyHashMap() {
        arr.clear();
        arr.resize(MOD);
    }
    
    int getHash(int key) {
        return key % MOD;
    }
    
    void put(int key, int value) {
        int h = getHash(key);
        arr[h].push_back({key, value});
    }
    
    int get(int key) {
        int h = getHash(key);
        for (int i = arr[h].size() - 1; i >= 0; i--) {
            if (arr[h][i].first == key) return arr[h][i].second;
        }
        
        return -1;
    }
    
    void remove(int key) {
        int h = getHash(key);
        for (int i = arr[h].size() - 1; i >= 0; i--) {
            if (arr[h][i].first == key) arr[h][i].second = -1;
        }
    }
private:
    const int MOD = 1000;
    vector<vector<pair<int, int>>> arr;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */