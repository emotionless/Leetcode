class Solution {
public:
    
    void solve(int cur, int remaining, const int &k, int num, vector<int> &ans) {
        if (remaining == 0) {
            ans.push_back(num);
            return;
        }
        if ((cur + k) < 10) {
            solve(cur + k, remaining - 1, k, num * 10 + cur + k, ans);
        }
        if ((cur - k) >= 0 && k) {
            solve(cur - k, remaining - 1, k, num * 10 + cur - k, ans);
        }
        
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for (int i = 1; i <= 9; i++) {
            solve(i, n - 1, k, i, ans);
        }
        return ans;
    }
};