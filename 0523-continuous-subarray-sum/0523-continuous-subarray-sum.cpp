class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        set<int> vis;
        int n = nums.size();
        if(n == 0) return false;
        if(k == 0) {
            for(int i = 1; i < n; i++) {
                if(nums[i] == 0 && nums[i-1] == 0) return true;
            }
            return false;
        }
        int sum = 0;
        int pre1 = -1, pre2 = -1;
        vis.insert(0);
        for(int i = 0; i < n; i++) {
            vis.insert(pre2);
            sum += nums[i];
            sum %= k;
            if(i && vis.find(sum) != vis.end()) {
                return true;
            }
            swap(pre1, pre2);
            pre1 = sum;
        }
        return false;
    }
};