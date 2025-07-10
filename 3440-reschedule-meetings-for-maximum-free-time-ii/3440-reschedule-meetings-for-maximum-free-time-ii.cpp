class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int last = 0;
        int k = 1;
        int n = startTime.size();
        vector<int> container(n + 2, 0);
        for (int i = 0; i < n; i++) {
            container[i] = (startTime[i] - last);
            last = endTime[i];
        }
        container[n] = (eventTime - last);
        container[n+1] = 0;

        int sz = n + 2;
        vector<int> mx(sz, 0);
        mx[sz - 1] =  container[sz - 1];
        for (int i =  sz - 2; i >= 0; i--) {
            mx[i] = max(container[i], mx[i+1]);
        }
        int leftMx = 0;
        int ans = 0;
        for (int i = 0; i < sz - 2; i++) {
            int rightMx = mx[i+2];  // check validation
            if (max(leftMx, rightMx) >= (endTime[i] - startTime[i])) {
                ans = max(ans, container[i] + container[i+1] +  (endTime[i] - startTime[i]));
            } else  {
                ans = max(ans, container[i] + container[i+1]);
            }
            leftMx = max(leftMx, container[i]);
        }
        return ans;
    }
};