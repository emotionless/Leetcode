class Solution {
public:
    
    int traverse(int ind, int x, int y, int n, string &str) {
        if (ind == str.size()) return 0;
        if (str[ind] == 'U') x -= 1;
        else if (str[ind] == 'R') y += 1;
        else if (str[ind] == 'D') x += 1;
        else y -= 1;
        if (x >= 0 && x < n && y >= 0 && y < n) {
            return 1 + traverse(ind + 1, x, y, n, str);
        }
        return 0;
    }
    
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ans;
        for (int i = 0; i < s.size(); i++) {
            ans.push_back(traverse(i, startPos[0], startPos[1], n, s));
        }
        return ans;
    }
};