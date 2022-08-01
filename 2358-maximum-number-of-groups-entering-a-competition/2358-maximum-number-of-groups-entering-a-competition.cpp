class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        int ans = 0;
        for (int i = 1; n >= i; i++) {
            ans = i;
            n -= i;
        }
        return ans;
    }
};