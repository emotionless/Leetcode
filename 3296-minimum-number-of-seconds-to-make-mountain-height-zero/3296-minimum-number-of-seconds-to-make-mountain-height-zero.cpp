class Solution {
public:
    long long getMaxHeights(long long worker, long long seconds) {
        long long st = 0, ed = 1e6;
        long long ans = 0;
        while (st <= ed) {
            long long mid = (st + ed) / 2ll;
            long long total = ((mid*(mid + 1ll)) / 2ll) * worker;
            if (total <= seconds) {
                ans = mid;
                st = mid + 1;
            } else  {
                ed = mid - 1;
            }
        }
        return ans;
    }
    long long totalHeights(long long seconds, vector<int> &workerTimes) {
        int n = workerTimes.size();
        long long total = 0ll;
        for (auto worker : workerTimes) {
            long long heights = getMaxHeights(worker, seconds);
            total += heights;
        }
        return total;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int n = workerTimes.size();
        long long st = 0, ed = 1e16;
        long long ans = 0;
        while (st <= ed) {
            long long mid = (st + ed)/2ll;
            long long heights = totalHeights(mid, workerTimes);
            // cout << mid << " " << heights << endl;
            if ( heights >= mountainHeight) {
                ans = mid;
                ed=mid-1;
                // cout << ans<<endl;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
};