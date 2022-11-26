class Solution {
public:
    struct interval {
        int st, ed, pro;
        interval(int _st, int _ed, int _pro) {
            st = _st;
            ed = _ed;
            pro = _pro;
        }
    };
    struct comparator {
        bool operator()(const interval &A, const interval &B) {
            return A.st < B.st;
        }
    };
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        for (int i = 0; i < n; i++) {
            arr.push_back(interval(startTime[i], endTime[i], profit[i]));
        }
        sort(arr.begin(), arr.end(), comparator());
        map<int, int> dp;
        int ans = 0;
        int pre = 0;
        for (int i = arr.size() - 1; i >= 0; i--) {
            int st = arr[i].st;
            int ed = arr[i].ed;
            int pro = arr[i].pro;
            auto it = dp.upper_bound(ed - 1);
            // cout << st  << endl;
            if (it == dp.end()) {
               dp[st] = pro; 
            } else {
                dp[st] = max(dp[st], (it->second) + pro);
            }
            dp[st] = max(dp[st], pre);
            pre = dp[st];
            // cout << st << " " << dp[st] << endl;
            ans = max(ans, dp[st]);
        }
        return ans;
    }
private:
    vector<interval> arr;
};