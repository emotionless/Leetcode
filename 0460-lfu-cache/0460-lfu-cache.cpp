class LFUCache {
public:
    LFUCache(int capacity) {
        cap = capacity;
        valuesWithFreq.clear();
        mp.clear();
        listIterator.clear();
        minFreq = 0;
        size = 0;
    }
    
    int get(int key) {
        // cout << key << endl;
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        // cout << "here" << endl;
        int &freq = mp[key].second;
        // cout << " freq " << freq << endl;
        auto it = listIterator[key];
        valuesWithFreq[freq].erase(it);
        freq++;
        valuesWithFreq[freq].push_back(key);
        listIterator[key] = --valuesWithFreq[freq].end();
        if (valuesWithFreq[minFreq].size() == 0) {
            //valuesWithFreq.erase(minFreq);
            minFreq++;
        }
        return mp[key].first;
    }
    
    void put(int key, int value) {
        if (cap == 0) return;
        int storedValue = get(key);
        // cout << key << " " << storedValue << endl;
        if (storedValue != -1) {
            mp[key].first = value;
            return;
        }
        // cout << valuesWithFreq.size() << endl;
        if (size == cap) {
            auto &lst = valuesWithFreq[minFreq];
            int deleteKey = *lst.begin();
            mp.erase(deleteKey);
            lst.pop_front();
            listIterator.erase(deleteKey);
            // cout << "delete: " << deleteKey << endl;
            size--;
        }
        minFreq = 1;
        mp[key] = {value, 1};
        valuesWithFreq[1].push_back(key);
        listIterator[key] = (--valuesWithFreq[1].end());
        size++;
        
        return;
    }
private:
    int cap, minFreq = 0, size = 0;
    unordered_map<int, list<int>> valuesWithFreq;
    unordered_map<int, pair<int, int>> mp; // key to {value, freq}
    unordered_map<int, list<int>::iterator> listIterator;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */