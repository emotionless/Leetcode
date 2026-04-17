class Solution {
public:
    int reverseNumber(int num) {
        int ret = 0;
        while (num > 0) {
            ret = ret * 10 + num % 10;
            num /= 10;
        }
        return ret;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> store;
        
        int ans = INT_MAX;
        for  (int  i =  0; i < n; i++) {
            int num = reverseNumber(nums[i]);
            if (store.find(nums[i]) != store.end()) {
                ans = min(ans, i - store[nums[i]]);
            }
            store[num] = i;
        }
        return  ans  == INT_MAX? -1 : ans;
    }
};