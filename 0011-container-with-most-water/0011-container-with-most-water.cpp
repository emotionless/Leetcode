class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0, j = heights.size() - 1;
        int ans = 0;
        while (i < j) {
            int mn = min(heights[i], heights[j]);
            ans = max(ans, mn * (j - i));
            while (i < j && heights[i] == mn) {
                i++;
            }
            while (j > i && heights[j] == mn) {
                j--;
            }
        }
        return ans;
    }
};