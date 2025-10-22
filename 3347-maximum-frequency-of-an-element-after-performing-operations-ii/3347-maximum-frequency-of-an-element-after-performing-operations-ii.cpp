class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        set<int> container;
        unordered_map<int, int> counter, degree;
        for (auto &num : nums) {
            container.insert(num - k);
            container.insert(num + k + 1);
            container.insert(num);
            degree[num - k]++;
            degree[num + k + 1]--;
            counter[num]++;
        }
        int ans = 0;
        int tot = 0;
        for (auto &v : container) {
            tot += degree[v];
            ans = max(ans, counter[v] + min(tot - counter[v], numOperations));
        }
        return ans;
    }
};