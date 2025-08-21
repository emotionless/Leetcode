class Solution {
public:
    
    int countRect(const vector<int> &arr) {
        int ret = 0;
        int m = arr.size();
        stack<int> stak;
        vector<int> sum(m, 0);
        for (int i = 0; i < m; i++) {
            while (!stak.empty() && arr[stak.top()] > arr[i]) {
                stak.pop();
            }
            if (stak.empty()) {
                sum[i] = arr[i] * (i+1);
            } else {
                int preInd = stak.top();
                sum[i] = sum[preInd];
                sum[i] += arr[i] * (i - preInd);
            }
            stak.push(i);
        }
        for (auto v : sum) ret += v;
        return ret;
    }
    
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> csum;
        csum.resize(m, 0);
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    csum[j] = 0;
                } else {
                    csum[j]++;
                }
            }
            res += countRect(csum);
        }
        return res;
    }
};