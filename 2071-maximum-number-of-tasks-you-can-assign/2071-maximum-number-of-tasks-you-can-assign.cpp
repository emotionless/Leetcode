class Solution {
public:
    
    bool isPossible(vector<int> &tasks, int k, vector<int> &workers, int pills, int strength) {
        multiset<int> container;
        for (auto &worker : workers) {
            container.insert(worker);
        }
        for (int i = k - 1; i >= 0; i--) {
            int task = tasks[i];
            if (container.empty()) return false;
            auto it = container.end();
            it--;
            if (*it >= task) {
                container.erase(it);
                continue;
            }
            if (!pills) return false;
            auto larger = container.upper_bound(task - strength - 1);
            if (larger == container.end()) return false;
            if ((*larger + strength) < task) {
                return false;
            }
            container.erase(larger);
            pills--;
        }
        return true;
    }
    
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        
        int st = 0, ed = tasks.size(), ans = 0;
        while (st <= ed) {
            int mid = (st + ed) / 2;
            if (isPossible(tasks, mid, workers, pills, strength)) {
                ans = mid;
                st = mid + 1;
            } else {
                ed = mid - 1;
            }
        }
        
        return ans;
    }
};