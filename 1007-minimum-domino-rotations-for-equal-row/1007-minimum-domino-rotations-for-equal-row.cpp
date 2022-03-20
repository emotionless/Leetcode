class Solution {
public:
    
    int getMinimum(int val, const vector<int> A, const vector<int> B) {
        int n = A.size();
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if (A[i] == val) continue;
            else if (B[i] == val) {
                cnt++;
            } else {
                return INT_MAX;
            }
        }
        return cnt;
    }
    
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int ans = INT_MAX;
        ans = min(ans, getMinimum(A[0], A, B));
        ans = min(ans, getMinimum(A[0], B, A));
        ans = min(ans, getMinimum(B[0], A, B));
        ans = min(ans, getMinimum(B[0], B, A));
        
        if (ans == INT_MAX) return -1;
        return ans;
    }
};