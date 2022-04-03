class Solution {
public:
    
    int longestIncreasingSubsequence(vector<int> &arr, int st, int k) {
        vector<int> container;
        for (int i = st; i < arr.size(); i+=k) {
            int v = arr[i];
            auto it = lower_bound(container.begin(), container.end(), v+1);
            if (it == container.end()) {
                container.push_back(v);
            } else {
                *it = v;
            }
        }
        return container.size();
    }
    
    int kIncreasing(vector<int>& arr, int k) {
        int ans = 0;
        for (int i = 0; i < k; i++) {
            ans += longestIncreasingSubsequence(arr, i, k);
        }
        return arr.size() - ans;
    }
};