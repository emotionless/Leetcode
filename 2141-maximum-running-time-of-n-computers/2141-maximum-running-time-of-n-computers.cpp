class Solution {
public:
    
    long long solve(long long mx, vector<int> &batteries) {
        long long sum = 0;
        for (auto v : batteries) {
            sum += min((long long)v, mx);
        }
        long long have = sum/mx;
        // cout << mx << " " << have << endl;
        return have;
    }
    
    long long maxRunTime(int N, vector<int>& batteries) {
        n = N;
        long long st = 1, ed = 1e15;
        long long ans = 0;
        while (st <= ed) {
            long long mid = (st + ed) / 2;
            long long have = solve(mid, batteries);
            // cout << have << endl;
            if (solve(mid, batteries) >= n) {
                ans = mid;
                // cout << mid << endl;
                st = mid + 1;
            } else {
                ed = mid - 1;
            }
        }
        return ans;
    }
private:
    int n;
};