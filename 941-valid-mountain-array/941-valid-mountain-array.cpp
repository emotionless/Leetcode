class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return false;
        int ind = 0;
        while (ind < (n-1)) {
            if (arr[ind + 1] > arr[ind]) ind++;
            else break;
        }
        int lastInd = n - 1;
        while (lastInd >= ind && lastInd > 0) {
            if (arr[lastInd - 1] > arr[lastInd]) lastInd--;
            else break;
        }
        if (ind == 0 || lastInd == (n-1)) return false;
        return lastInd == ind;
    }
};