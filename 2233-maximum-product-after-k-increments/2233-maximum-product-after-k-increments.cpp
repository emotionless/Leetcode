class Solution {
public:
    const int MOD = 1e9 + 7;
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> pq;
        for (auto &v : nums) {
            pq.push(v);
        }
        while (k) {
            int top = pq.top();
            pq.pop();
            top++;
            pq.push(top);
            k--;
        }
        long long res = 1ll;
        while (!pq.empty()) {
            res = (res * pq.top()) % MOD;
            pq.pop();
        }
        return res;
    }
};