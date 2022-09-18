class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;
        int mxLeft[n], mxRight[n];
        memset(mxLeft, 0, sizeof mxLeft);
        memset(mxRight, 0, sizeof mxRight);
        mxLeft[0] = height[0];
        for(int i = 1; i < n; i++) {
            mxLeft[i] = max(mxLeft[i-1], height[i]);
        }
        mxRight[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--) {
            mxRight[i] = max(mxRight[i+1], height[i]);
        }
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += max(0, min(mxLeft[i], mxRight[i]) - height[i]);
        }
        return sum;
    }
};