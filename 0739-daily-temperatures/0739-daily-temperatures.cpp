class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            int j = i + 1;
            while (j < n) {
                if (temperatures[j] > temperatures[i]) break;
                if (answer[j] == 0) j = n;
                else j += answer[j];
            }
            if (j < n) {
                answer[i] = j - i;
            }
        }
        return answer;
    }
};