class MyHashSet {
public:
    MyHashSet() {
        memset(vis, false, sizeof (vis));
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
    bool vis[1000001];
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */