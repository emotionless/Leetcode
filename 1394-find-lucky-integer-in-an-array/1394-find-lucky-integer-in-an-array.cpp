class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> counter;
        for(auto num : arr) {
            counter[num]++;
        }
        int ans = -1;
        for (auto obj : counter) {
            if (obj.first == obj.second) {
                ans = max(ans, obj.first);
            }
        }
        return ans;
    }
};