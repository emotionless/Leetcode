class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> seen;
        for (auto v : arr) {
            seen.insert(v);
        }
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int pre = arr[i];
                int now = arr[j];
                int cnt = 2;
                while (seen.find(pre+now) != seen.end()) {
                    int nxt = pre + now;
                    pre = now;
                    now = nxt;
                    cnt++;
                }
                ans = max(ans, cnt);
            }
        }
        if (ans <= 2) return 0;
        return ans;
    }
};