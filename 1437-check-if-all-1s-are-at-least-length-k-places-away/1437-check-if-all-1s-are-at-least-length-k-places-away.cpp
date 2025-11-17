class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last = -k - 10;
        for (int i = 0; i  < nums.size(); i++) {
            if (nums[i] == 1) {
                if ((i-last-1) < k) return false;
                last = i;
            }
        }
        return true;
    }
};