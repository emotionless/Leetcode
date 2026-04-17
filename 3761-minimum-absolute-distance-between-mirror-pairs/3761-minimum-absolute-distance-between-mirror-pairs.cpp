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
        unordered_map<int, stack<int>> store;
        for(int i = n - 1;  i  >= 0; i--) {
            store[nums[i]].push(i);
        }
        int ans = INT_MAX;
        for  (int  i =  0; i < n; i++) {
            int num = reverseNumber(nums[i]);
            auto &cur = store[num];
            while (!cur.empty()  && cur.top() <= i) {
                cur.pop();
            }
            if (!cur.empty()) {
                ans  =  min(ans, cur.top() - i);
            }
        }
        return  ans  == INT_MAX? -1 : ans;
    }
};