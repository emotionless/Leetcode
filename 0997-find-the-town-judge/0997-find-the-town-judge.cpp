class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, int> degree, from;
        for (auto con : trust) {
            degree[con[1]]++;
            from[con[0]]++;
        }
        int ans = -1;
        for (int i = 1; i <= n; i++) {
            if (degree[i] == (n-1) && from[i] == 0) {
                if (ans != -1) return -1;
                ans = i;
            }
        }
        return ans;
    }
};