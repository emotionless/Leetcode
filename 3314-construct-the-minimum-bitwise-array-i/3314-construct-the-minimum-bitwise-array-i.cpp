class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        int ind = 0;
        for (int &num : nums) {
            for  (int i = 1; i < num; i++) {
                if ((i | (i+1)) == num) {
                    ans[ind] = i;
                    break;
                }
            }
            ind++;
        }
        return ans;
    }
};