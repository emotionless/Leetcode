class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            while (j < n && prices[j] == (prices[j-1] -1)) {
                j++;
            }
            long long now = j - i;
            i = j - 1;
            ans += (now*(now + 1))/2;
        }
        return ans;
    }
};