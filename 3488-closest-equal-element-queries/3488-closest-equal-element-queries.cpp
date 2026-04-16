class Solution {
public:
    int minimumDist(int i, int j, int n) {
        return min( abs(i - j), min(n - j + i, n - i + j ));
    }
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, int> last;
        vector<int> closest(n, n + 1);
        for (int i = 0; i < n; i++) last[nums[i]] = i;
        for (int i = 0; i < n; i++) {
            closest[i] = minimumDist(i, last[nums[i]], n);
            last[nums[i]] = i;
        }
        last.clear();
        for (int i = n-1; i >= 0; i--) last[nums[i]] = i;
        
        for (int i = n-1; i >= 0; i--) {
            closest[i] = min(closest[i], minimumDist(i, last[nums[i]], n));
            last[nums[i]] = i;
        }
        // for (int i = 0; i < n; i++) {
        //     cout << i << " " << closest[i] << endl;
        // }
        vector<int> ans;
        for (auto num : queries) {
            if (closest[num] == 0) ans.push_back(-1);
            else ans.push_back(closest[ num ]);
        }
        return ans;
    }
};