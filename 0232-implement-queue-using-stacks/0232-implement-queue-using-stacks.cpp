class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while (container1.size()) {
            container2.push(container1.top());
            container1.pop();
        }
        container1.push(x);
        while (container2.size()) {
            container1.push(container2.top());
            container2.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = container1.top();
        container1.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        return container1.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return container1.size() > 0? false : true;
    }
private:
    stack<int> container1, container2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */