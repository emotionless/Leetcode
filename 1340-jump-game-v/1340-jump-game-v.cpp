class Solution {
public:

    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        dp.resize(n, -1);
        k = d;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, 1 + solve(i, arr));
            // cout << i << " " << 1 + solve(i, arr) << endl;
        }
        return ans;
    }
private:
    vector<int> dp;
    int n, k;

    int solve(int ind, vector<int> &arr) {
        if (ind < 0 || ind >= n) return 0;

        int &ret = dp[ind];
        if (ret != -1) return ret;
        ret = 0;
        for (int i = ind - 1; i  >= max(0, ind - k); i--) {
            if (arr[i] < arr[ind]) {
                ret = max(ret, 1 + solve(i, arr));
            }
            else {
                break;
            }
        }
        for (int i = ind + 1; i  <= min(n-1, ind + k); i++) {
            if (arr[i] < arr[ind]) {
                ret = max(ret, 1 + solve(i, arr));
            }
            else {
                break;
            }
        }
        return ret;
    }
};