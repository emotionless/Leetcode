class FreqStack {
public:
    
    struct comparator {
        bool operator()(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b) {
            if (a.first == b.first) return a.second.first < b.second.first;
            return a.first < b.first;
        }
    };
    
    FreqStack() {
        counter.clear();
    }
    
    void push(int val) {
        counter[val]++;
        pq.push(make_pair(counter[val], make_pair(steps++, val)));
    }
    
    int pop() {
        auto top = pq.top();
        pq.pop();
        counter[top.second.second]--;
        return top.second.second;
    }
private:
    int steps = 0;
    priority_queue<pair<int, pair<int, int>>> pq;
    unordered_map<int, int> counter;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

/*

1 1 1
*/