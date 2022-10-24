class Solution {
public:
    
    int getMaxLength(int mask, int seen) {
        int &ret = dp[mask];
        if (ret != -1) return ret;
        ret = 0;
        for (int ind = 0; ind < nums.size(); ind++) {
            if (!(mask&(1<<ind)) && (seen&nums[ind]) == 0) {
                ret = max(ret, __builtin_popcount(nums[ind]) + getMaxLength(mask|(1<<ind), seen|nums[ind]));
            }
        }
        return ret;
    }
    
    int maxLength(vector<string>& arr) {
        dp.resize(1<<arr.size(), -1);
        for (auto str : arr) {
            int decimal = 0;
            for (auto ch : str) {
                decimal |= (1<<(ch-'a'));
            }
            if (__builtin_popcount(decimal) == str.size()) {
                nums.push_back(decimal);
            }
        }
        return getMaxLength(0, 0);
    }
private:
    vector<int> dp, nums;
};