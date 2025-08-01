class Solution {
public:
    int getValue(vector<int> &cur, int pos) {
        if(pos < 0 || pos >= cur.size()) return 0;
        return cur[pos];
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for (int i = 1; i < numRows; i++) {
            vector<int> tmp;
            for (int j = 0; j < ans[i-1].size() + 1; j++) {
                tmp.push_back(getValue(ans[i-1], j)  +  getValue(ans[i-1], j-1));
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};