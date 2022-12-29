class Solution {
public:
    
    struct compare {
        bool operator()(const vector<int> &a, const vector<int> &b) {
            if (a[1] == b[1]) return -a[2] < -b[2];
            return -a[1] < -b[1];
        }
    };
    
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for (int i = 0; i < n; i++) {
            arr.push_back({tasks[i][0], tasks[i][1], i});
        }
        sort(arr.begin(), arr.end());
        int i = 0;
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;
        vector<int> ans;
        long long sum = 0;
        while (!pq.empty() || i < n) {
            if (pq.empty()) {
                pq.push(arr[i++]);
            } else {
                auto top = pq.top();
                pq.pop();
                ans.push_back(top[2]);
                sum = max(sum, (long long)top[0]);
                sum += top[1];
                while (i < n && arr[i][0] <= sum) {
                    pq.push(arr[i++]);
                }
            }
        }
        return ans;
    }
private:
    vector<vector<int>> arr;
};