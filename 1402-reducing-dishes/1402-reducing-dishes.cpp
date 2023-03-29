class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int ans = 0;
        int n = satisfaction.size();
        for (int i = 0; i < n; i++) {
            int sum = 0, k = 1;
            for (int j = i; j < n; j++) {
                sum += k*satisfaction[j];
                k++;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};