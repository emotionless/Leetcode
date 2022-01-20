class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = 0;
        for (auto roll : rolls) {
            sum += roll;
        }
        int total = mean * (n + m);
        int rest = total - sum;
        vector<int> ans;
        while (n && rest > 0) {
            int canTake = rest - n + 1;
            if (canTake <= 0) break;
            int mn = min(6, canTake);
            ans.push_back(mn);
            rest -= mn;
            n--;
        }
        if (n != 0 || rest != 0) return {};
        return ans;
    }
};