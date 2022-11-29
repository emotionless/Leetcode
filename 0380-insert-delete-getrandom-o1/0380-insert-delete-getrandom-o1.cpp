class RandomizedSet {
public:
    /** Initialize your data structure here. */
    set<int> S;
    RandomizedSet() {
        srand(time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (S.find(val) == S.end()) {
            S.insert(val);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (S.find(val) == S.end()) {
            return false;
        }
        
        S.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        set<int>:: iterator it = S.begin();
        int r = rand() % S.size();
        advance(it, r);
        
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */