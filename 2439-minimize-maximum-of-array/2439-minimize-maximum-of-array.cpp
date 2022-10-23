class Solution {
public:
    
    bool possible(vector<int> &nums, const int &tar) {
        int n = nums.size();
        long long sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            sum += tar - nums[i];
            if (sum > 0) sum = 0;
        }
        return sum >= 0;
    }
    
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        /*
        int st = 0, ed = *max_element(nums.begin(), nums.end());
        int ans = ed;
        while (st <= ed) {
            int mid = (st + ed) / 2;
            if (possible(nums, mid)) {
                ans = mid;
                ed = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        */
        long long sum = 0;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            ans = max(ans, sum/(i+1) + (sum%(i+1)?1:0));
        }
        
        return ans;
    }
};