class Solution {
public:
    
    int getMaxArea(vector<int> &nums) {
        int n = nums.size();
        int ans = 0;
        stack<int> container;
        vector<int> left(n, 0);
        for (int i = 0; i < n; i++) {
            while (container.size() > 0 && nums[container.top()] >= nums[i]) {
                container.pop();
            }
            int ind = -1;
            if (container.size()) {
                ind = container.top();
            }
            left[i] = (i - ind);
            container.push(i);
        }
        while(!container.empty()) {
            container.pop();
        }
        for (int i = n-1; i >= 0; i--) {
            while (container.size() > 0 && nums[container.top()] >= nums[i]) {
                container.pop();
            }
            int ind = n;
            if (container.size()) {
                ind = container.top();
            }
            ans = max(ans, nums[i] * ((ind - i) + left[i] - 1));
            container.push(i);
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> arr;
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        arr.resize(m, 0);
        int answer = 0;
        for (auto row : matrix) {
            for (int j = 0; j < m; j++) {
                if (row[j] == '0') arr[j] = 0;
                else arr[j]++;
            }
            answer = max(answer, getMaxArea(arr));
        }
        return answer;
    }
};