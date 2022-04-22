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
        for (auto it = arr[h].begin(); it != arr[h].end(); it++) {
            if (it->first == key) {
                it->second = value;
                return;
            }
        }
        arr[h].push_back({key, value});
        
        return;
    }
    
    int get(int key) {
        int h = getHash(key);
        for (auto it = arr[h].begin(); it != arr[h].end(); it++) {
            if (it->first == key) return it->second;
        }
        
        return -1;
    }
    
    void remove(int key) {
        int h = getHash(key);
        for (auto it = arr[h].begin(); it != arr[h].end(); it++) {
            if (it->first == key) {
                arr[h].erase(it);
                return;
            }
        }
    }
private:
    const int MOD = 1000;
    vector<list<pair<int, int>>> arr;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */