class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> container;
        vector<int> right(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            while (!container.empty() && heights[container.top()] >= heights[i]) {
                container.pop();
            }
            int mx = n;
            if (!container.empty()) {
                mx = container.top();
            }
            right[i] = mx - i;
            container.push(i);
        }
        while (!container.empty()) container.pop();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            while (!container.empty() && heights[container.top()] >= heights[i]) {
                container.pop();
            }
            int mn = -1;
            if (!container.empty()) {
                mn = container.top();
            }
            int left = i - mn;
            ans = max(ans, (right[i] + left - 1) * heights[i]);
            container.push(i);
        }
        return ans;
    }
};