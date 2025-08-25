class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 0) {
            return {};
        }
        int m = mat[0].size();
        if (m == 0) {
            return {};
        }
        vector<vector<int>> store;
        store.resize(n+m-1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                store[i+j].push_back(mat[i][j]);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n+m -1; i++) {
            if (i%2 == 0) {
                for (int j = store[i].size() - 1; j >= 0; j--) {
                    ans.push_back(store[i][j]);
                }
            } else {
                for (auto num : store[i]) {
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};

/*

0 0
0 1
1 0
2 0
1 1
0 2
0 3
1 2
2 1
3 0
3 1
2 2
1 3
2 3
3 2
3 3

*/