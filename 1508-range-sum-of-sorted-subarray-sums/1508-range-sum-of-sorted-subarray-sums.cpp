class Solution {
public:
    const int MOD = 1e9 + 7;
    struct comparator {
        bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
            return -a.first < -b.first;
        }
    };
    
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> pq;
        for (int i = 0; i < n; i++) {
            pq.push(make_pair(nums[i], i));
        }
        int cnt = 0;
        int sum = 0;
        while (!pq.empty()) {
            cnt++;
            if (cnt > right) break;
            auto top = pq.top();
            pq.pop();
            if (cnt >= left && cnt <= right) {
                sum = (sum + top.first) % MOD;
            }
            if ((top.second + 1) < n) {
                top.second++;
                top.first += nums[top.second];
                top.first %= MOD;
                pq.push(top);
            }
        }
        return sum;
    }
};