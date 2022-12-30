class Solution {
public:
    
    bool possible(vector<int> &price, int target, int k) {
        int n = price.size();
        int pre = price[0];
        k--;
        for (int i = 1; i < n; i++) {
            if ((price[i] - pre) >= target) {
                k--;
                pre = price[i];
            }
        }
        return k <= 0;
    }
    
    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size();
        sort(price.begin(), price.end());
        int ans = 0;
        int st = 0, ed = price[n-1];
        while (st <= ed) {
            int mid = (st + ed) / 2;
            if (possible(price, mid, k)) {
                ans = mid;
                st = mid + 1;
            } else {
                ed = mid - 1;
            }
        }
        return ans;
    }
};