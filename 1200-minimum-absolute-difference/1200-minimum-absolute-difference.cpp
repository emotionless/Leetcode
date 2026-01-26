class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> answer;
        int n = arr.size();
        int mn = INT_MAX;
        for (int i = 1; i < n; i++) {
            if ((arr[i] - arr[i-1]) < mn) {
                answer.clear();
                mn = arr[i] - arr[i-1];
                answer.push_back({arr[i-1], arr[i]});
            } else if ((arr[i] - arr[i-1]) == mn) {
                answer.push_back({arr[i-1], arr[i]});
            }
        }
        return answer;
    }
};