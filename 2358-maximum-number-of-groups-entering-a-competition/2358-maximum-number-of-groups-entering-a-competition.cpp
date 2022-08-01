class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        return sqrt(2*n + 0.25f) - 0.5f;
        int ans = 0;
        for (int i = 1; n >= i; i++) {
            ans = i;
            n -= i;
        }
        return ans;
    }
};