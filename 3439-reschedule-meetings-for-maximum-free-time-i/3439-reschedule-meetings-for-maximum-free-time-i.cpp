class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int last = 0;
        vector<int> container;
        int n = startTime.size();
        for (int i = 0; i < n; i++) {
            container.push_back(startTime[i] - last);
            last = endTime[i];
        }
        container.push_back(eventTime - last);

        int sz = container.size();
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < sz; i++) {
            sum += container[i];
            if ((i-k-1) >= 0) {
                sum -= container[i-k-1];
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};