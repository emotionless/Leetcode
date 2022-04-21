class MyHashSet {
public:
    MyHashSet() {
        vis.resize(1e6 + 1, false);
    }
    
    void add(int key) {
        vis[key] = true;
    }
    
    void remove(int key) {
        vis[key] = false;
    }
    
    bool contains(int key) {
        return vis[key];
    }
private:
    vector<bool> vis;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */