class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int len = s.length();
        int ans = 0;
        for(int i = 0; i < len;) {
            int sum = 0;
            int mx = cost[i];
            int j = i;
            for(j = i; j < len; j++) {
                if (s[j] == s[i]) {
                    mx = max(mx, cost[j]);
                    sum += cost[j];
                } else {
                    break;
                }
            }
            ans += sum - mx;
            i = j;
        }
        return ans;
    }
};