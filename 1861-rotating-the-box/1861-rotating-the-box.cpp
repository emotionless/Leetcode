class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        if (n == 0) return {};
        int m = box[0].size();
        vector<vector<char>> rotatedBox(m, vector<char>(n, ' '));
        int c = 0;
        for (int i = n - 1; i >= 0; i--) {
            vector<char> tmp;
            int k = 0;
            for (int j = m - 1; j >= 0; j--) {
                tmp.push_back(box[i][j]);
                if (box[i][j] == '*') {
                    k = tmp.size();
                } else if (box[i][j] == '#') {
                    swap(tmp[k], tmp.back());
                    k++;
                }
            }
            reverse(tmp.begin(), tmp.end());
            for (int j = 0; j < m; j++) {
                rotatedBox[j][c] = tmp[j];
            }
            c++;
        }
        return rotatedBox;
    }
};