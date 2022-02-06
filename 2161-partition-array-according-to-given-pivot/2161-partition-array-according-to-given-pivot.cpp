class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans, left, right;
        int i = 0, j = n - 1, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) left.push_back(nums[i]);
            else if (nums[i] > pivot) right.push_back(nums[i]);
            else cnt++;
        }
        for (auto v : left) {
            ans.push_back(v);
        }
        for (int i = 0; i < cnt; i++) {
            ans.push_back(pivot);
        }
        for (auto v : right) {
            ans.push_back(v);
        }
        return ans;
    }
};