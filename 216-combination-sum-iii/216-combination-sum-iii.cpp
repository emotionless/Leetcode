class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        for(int i = 0; i < (1<<9); i++) {
            int bt = __builtin_popcount(i);
            if (bt != k) continue;
            vector<int> tmp;
            int sum = 0;
            for(int j = 0; j < 9; j++) {
                if (i&(1<<j)) {
                    sum += j + 1;
                    tmp.push_back(j+1);
                }
            }
            if (sum == n) {
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};