class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int count = 0, ans = 0;
        int ind = 0;
        while (ind < n && seats[ind] == 0) ind++;
        ans = max(ans, ind);
        ind = n - 1;
        while (ind >= 0 && seats[ind] == 0) ind--;
        ans = max(ans, n - ind - 1);
        for (auto seat : seats) {
            if (seat == 1) {
                count = 0;
            } else {
                count++;
            }
            ans = max(ans, (count + 1) / 2);
        }
        return ans;
    }
};