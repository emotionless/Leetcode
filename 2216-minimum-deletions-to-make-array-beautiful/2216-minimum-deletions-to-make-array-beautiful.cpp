class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            while (j < n && nums[j] == nums[i]) {
                cnt++;
                j++;
            }
            i = j;
        }
        if ((n+cnt)%2) cnt++;
        return cnt;
    }
};