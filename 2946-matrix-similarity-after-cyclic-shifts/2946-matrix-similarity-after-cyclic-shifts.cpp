class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        k = k % m;

        if (k == 0) return true;

        int str = k;
        int stc = m - k;

        for (int i = 0; i < n; i++) {
            int st = str;
            if (i%2==1) st = stc;
            int ind = 0;
            // cout << i << " " << st << endl;
            for (int j = st; ind < m ; ind++, j++) {
                int ind1 = j % m;
                if (mat[i][ind1] != mat[i][ind]) return false;
            }
        }
        return true;
    }
};