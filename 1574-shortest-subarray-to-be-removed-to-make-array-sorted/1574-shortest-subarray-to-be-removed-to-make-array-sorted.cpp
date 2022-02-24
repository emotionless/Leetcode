class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int ind = n - 2;
        while (ind >= 0 && arr[ind] <= arr[ind + 1]) {
            ind--;
        }
        ind++;
        int ans = ind;
        int pre = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (arr[i] < pre) break;
            while(ind < n && arr[ind] < arr[i]) {
                ind++;
            }
            ans = min(ans, ind - i - 1);
            pre = arr[i];
        }
        return max(0, ans);
    }
};