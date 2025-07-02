class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(banned.begin(), banned.end());
        int ind = 0;
        int sz = banned.size();
        int sum = 0;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            while (ind < sz && banned[ind] < i) {
                ind++;
            }
            if ((sum + i) <= maxSum) {
                if ((ind < sz && banned[ind] != i) || ind >= sz) {
                    sum += i;
                    cnt++;
                }
            } else {
                break;
            }
        }
        return cnt;
    }
};