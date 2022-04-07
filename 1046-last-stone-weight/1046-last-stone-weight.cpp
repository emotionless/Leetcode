class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (auto &stone : stones) {
            pq.push(stone);
        }
        while (pq.size() > 1) {
            auto num1 = pq.top();
            pq.pop();
            auto num2 = pq.top();
            pq.pop();
            if (num1 != num2) {
                pq.push(num1 - num2);
            }
        }
        if (pq.size() == 0) return 0;
        return pq.top();
    }
};