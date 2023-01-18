class Solution {
public:
    
    int maxSum(const vector<int> A) {
        int sum = 0, ans = 0;
        for(int i = 0; i < A.size(); i++) {
            sum += A[i];
            if (sum < 0) {
                sum = 0;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
    
    int maxSubarraySumCircular(vector<int>& A) {
        int mx = maxSum(A);
        int sum = 0;
        int m = INT_MIN;
        for(int i = 0; i < A.size(); i++) {
            sum += A[i];
            m = max(m, A[i]);
            A[i] *= -1;
        }
        if (m <= 0) return m;
        int mn = maxSum(A);
        return max(mx, sum + mn);
    }
};