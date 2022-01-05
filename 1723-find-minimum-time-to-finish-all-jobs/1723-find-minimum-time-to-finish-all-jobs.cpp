class Solution {
public:
    const int INF = 100000;
    
    bool possible(int ind, int target, vector<int> &workers, vector<int> &jobs) {
        if (ind < 0) {
            return true;
        }
        int ret = 0;
        for (int i = 0; i < workers.size(); i++) {
            if ((workers[i] + jobs[ind]) <= target) {
                workers[i] += jobs[ind];
                ret += possible(ind - 1, target, workers, jobs);
                if (ret) return ret;
                workers[i] -= jobs[ind];
            }
            if (workers[i] == 0) break;
        }
        return false;
    }
    
    int minimumTimeRequired(vector<int>& jobs, int k) {
        n = jobs.size();
        sort(jobs.begin(), jobs.end());
        int st = 0, ed = 1e9;
        int ans = ed;
        for (auto v : jobs) {
            st = max(st, v);
        }
        while (st <= ed) {
            int mid = (st + ed) / 2;
            vector<int> workers(k, 0);
            if (possible(n - 1, mid, workers, jobs)) {
                ans = mid;
                ed = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
private:
    int n;
};