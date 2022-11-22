class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        set<int> st;
        vector<int> left(n, 0), right(n, 0);
        for (int i = 0; i < n; i++) {
            auto it = st.upper_bound(nums[i]);
            if (it != st.end()) {
                st.erase(it);
            }
            st.insert(nums[i]);
            left[i] = i + 1 - st.size();
            if (left[i] == i) left[i] = n;
        }
        st.clear();
        for (int i = n-1; i >= 0; i--) {
            auto it = st.upper_bound(nums[i]);
            if (it != st.end()) {
                st.erase(it);
            }
            st.insert(nums[i]);
            right[i] = (n-i) - st.size();
            if (right[i] == ((n - i - 1))) right[i] = n;
        }
        int ans = n;
        for (int i = 0; i < n; i++) {
            ans = min(ans, left[i] + right[i]);
            // cout << left[i] << " " << right[i] << endl;
        }
        return ans;
    }
};