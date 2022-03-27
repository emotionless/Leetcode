class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (auto v : mat[i]) {
                sum += v;
            }
            pq.push({sum, i});
            if (pq.size() > k) pq.pop();
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};