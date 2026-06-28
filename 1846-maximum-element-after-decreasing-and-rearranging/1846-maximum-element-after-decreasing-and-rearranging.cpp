class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int mx = 1;
        for (int num : arr) {
            if (num >= mx) {
                mx++;
            }
        }
        return mx-1;
    }
};