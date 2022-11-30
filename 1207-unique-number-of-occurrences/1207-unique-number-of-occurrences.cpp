class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int pre = arr[0];
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] == pre) {
                cnt++;
            } else {
                if (arr[cnt-1] == INT_MAX) return false;
                arr[cnt-1] = INT_MAX;
                cnt = 1;
            }
            pre = arr[i];
        }
        if (arr[cnt-1] == INT_MAX) return false;
        return true;
    }
};