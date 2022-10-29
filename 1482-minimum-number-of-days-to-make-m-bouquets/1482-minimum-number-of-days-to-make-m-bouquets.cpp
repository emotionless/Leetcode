class Solution {
public:
    
    int numberOfBouquests(vector<int> &bloomDay, int limit, int m) {
        int bouquests = 0;
        int cnt = 0;
        for (auto &day : bloomDay) {
            if (day <= limit) {
                cnt++;
            } else {
                cnt = 0;
            }
            if (cnt == m) {
                bouquests++;
                cnt = 0;
            }
        }
        return bouquests;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int st = 0, ed = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while (st <= ed) {
            int mid = (st + ed) / 2;
            if (numberOfBouquests(bloomDay, mid, k) >= m) {
                ans = mid;
                ed = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
};