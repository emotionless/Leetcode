class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        int j = 0;
        const int INF = 1000000000;
        int last = INF;
        int next = -INF;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            while (j < n && j <= (i+k)) {
                if (nums[j] == key) {
                    next = j;
                    j++;
                    break;
                }
                j++;
            }
            // cout << i << " " << last << " " << next << endl;
            if (abs(i - last) <= k || abs(next - i) <= k) {
                ans.push_back(i);
            }
            if (nums[i] == key) last = i;
            if (next <= i) next = -INF;
        }
        return ans;
    }
};