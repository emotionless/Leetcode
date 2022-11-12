class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        while(!smaller.empty()) {
            smaller.pop();
        }
        while(!larger.empty()) {
            larger.pop();
        }
    }
    
    void addNum(int num) {
        smaller.push(num);
        if ((smaller.size() - larger.size()) == 2) {
            int top = smaller.top();
            smaller.pop();
            larger.push(-top);
        }
        if (larger.size() > 0 && smaller.top() > (-larger.top())) {
            int ts = smaller.top();
            int tl = larger.top();
            smaller.pop();
            larger.pop();
            larger.push(-ts);
            smaller.push(-tl);
            // cout << ts << " " << -tl << endl;
        }
    }
    
    double findMedian() {
        if (smaller.size() == larger.size()) return (smaller.top() - larger.top())/ 2.0;
        return smaller.top();
    }
private:
    priority_queue<int> smaller, larger;
    
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */