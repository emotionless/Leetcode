class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for (auto str : operations) {
            ans += (str[1] == '+'? 1 : -1);
        }
        return ans;
    }
};