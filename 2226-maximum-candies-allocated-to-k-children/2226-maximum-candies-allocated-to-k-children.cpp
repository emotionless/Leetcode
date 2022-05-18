class Solution {
public:
    
    long long solve(vector<int> &candies, int cur) {
        long long ret = 0;
        for (auto &candy : candies) {
            ret += candy / cur;
        }
        return ret;
    }
    
    int maximumCandies(vector<int>& candies, long long k) {
        int st = 1, ed = *max_element(candies.begin(), candies.end()), ans = 0;
        while (st <= ed) {
            int mid = (st + ed) / 2;
            if (solve(candies, mid) >= k) {
                ans = mid;
                st = mid + 1;
            } else {
                ed = mid - 1;
            }
        }
        return ans;
    }
};