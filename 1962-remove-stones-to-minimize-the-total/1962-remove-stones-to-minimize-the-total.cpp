class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int sum = 0;
        for (auto &pile : piles) {
            pq.push(pile);
            sum += pile;
        }
        while (k--) {
            if (pq.empty()) break;
            int top = pq.top();
            pq.pop();
            int half = top / 2;
            top -= half;
            sum -= half;
            pq.push(top);
        }
        return sum;
    }
};