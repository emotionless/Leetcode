class Solution {
public:
    
    long long can(vector<int> &time, long long now) {
        long long ret = 0;
        for (auto t : time) {
            ret += now/t;
        }
        return ret;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long st = 1ll, ed = 1e14 + 5;
        long long ans = 0ll;
        while (st <= ed) {
            long long mid = (st + ed)/2;
            if (can(time, mid) >= totalTrips) {
                ans = mid;
                ed = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
};