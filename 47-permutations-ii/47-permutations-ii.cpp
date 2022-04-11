class Solution {
public:
    void nextPermutation(vector<int>& nums, bool &isEnd) {
        int n = nums.size();
        int mx = -100;
        priority_queue<int, vector<int>, greater<>> st;
        int ind = n;
        int num = -100;
        for (int i = n - 1; i >= 0; i--) {
            st.push(nums[i]);
            mx = max(mx, nums[i]);
            if (nums[i] < mx) {
                int j = i + 1;
                while (j < n && nums[j] > nums[i]) {
                    j++;
                }
                nums[i] = nums[j-1];
                num = nums[i];
                ind = i + 1;
                break;
            }
        }
        if (ind == n) {
            isEnd = true;
            reverse(nums.begin(), nums.end());
            return;
        }
        while (ind < n && st.size()) {
            auto it = st.top();
            st.pop();
            if (it == num) {
                num = -100;
                continue;
            }
            nums[ind++] = it;
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        bool isEnd = false;
        do {
            nextPermutation(nums, isEnd);
            ans.push_back(nums);
        } while (!isEnd);
        return ans;
    }
};