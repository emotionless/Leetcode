class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int, vector<long long>> container;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            container[arr[i]].push_back(i);
        }
        vector<long long> ans(n, 0);
        for (auto element : container) {
            vector<long long> indexes = element.second;
            long long sum = 0;
            int sz = indexes.size();
            for (int i = 0; i < indexes.size(); i++) {
                sum += indexes[i];
                ans[indexes[i]] = indexes[i]*(i + 1) - sum;
            }
            sum = 0;
            for (int i = indexes.size() - 1; i >= 0; i--) {
                sum += indexes[i];
                ans[indexes[i]] += sum - indexes[i] * (sz - i);
            }
        }
        return ans;
    }
};