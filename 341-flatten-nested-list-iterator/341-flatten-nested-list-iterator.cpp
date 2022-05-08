/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        starts.push(nestedList.begin());
        ends.push(nestedList.end());
    }

    int next() {
        hasNext();
        int val = starts.top() -> getInteger();
        starts.top()++;
        return val;
    }

    bool hasNext() {
        while(!starts.empty()) {
            if(starts.top() == ends.top()) {
                starts.pop();
                ends.pop();
                continue;
            }
            auto top = starts.top();
            if(top -> isInteger()) {
                return true;
            }
            starts.top()++;
            starts.push(top -> getList().begin());
            ends.push(top -> getList().end());
        }
        return false;
    }
private:
    stack< vector<NestedInteger>:: iterator > starts, ends;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */