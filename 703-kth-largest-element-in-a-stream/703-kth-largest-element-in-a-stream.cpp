class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        for (auto &num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        K = k;
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > K) {
            pq.pop();
        }
        return pq.top();
    }
private:
    int K;
    priority_queue<int, vector<int>, greater<>> pq;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */