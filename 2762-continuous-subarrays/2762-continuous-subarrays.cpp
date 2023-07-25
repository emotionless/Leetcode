class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        multiset<int> container;
        int n = nums.size();
        long long ans = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            while(j < n) {
                container.insert(nums[j++]);
                int mn = *container.begin();
                auto it = container.end();
                it--;
                int mx = *it;
                if ((mx-mn) > 2) {
                    j--;
                    container.erase(nums[j]);
                    break;
                }
            }
            ans += container.size();
            container.erase(container.find(nums[i]));
        }
        return ans;
    }
};