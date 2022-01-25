class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int posSum = 0, negSum = 0;
        int ans = 0;
        for (auto v : nums) {
            posSum += v;
            negSum += v;
            if (posSum < 0) {
                posSum = 0;
            }
            if (negSum > 0) {
                negSum = 0;
            }
            ans = max(ans, max(abs(posSum), abs(negSum)));
        }
        return ans;
    }
};