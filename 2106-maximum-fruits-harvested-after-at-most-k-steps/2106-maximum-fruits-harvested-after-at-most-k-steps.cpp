class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int mx = fruits[n-1][0];
        vector<int> csum(mx  +  1, 0);
        for (auto fruit : fruits) {
            csum[fruit[0]] = fruit[1];
        }
        for (int i = 1; i <= mx; i++) {
            csum[i] += csum[i-1]; 
        }
        int ans = 0;
        for (int i = max(0, startPos - k); i <= startPos && i <= mx; i++) {
            int cur = getCumulativeSum(i, startPos, csum);
            int remaining = k - 2*(startPos - i);
            if (remaining >  0) {
                cur = getCumulativeSum(i, startPos + remaining, csum);
            }
            ans = max(ans, cur);
        }
        for (int i = startPos + 1; i <= (startPos + k) && i <= mx ; i++) {
            int cur = getCumulativeSum(startPos, i, csum);
            int remaining = k - 2*(i - startPos);
            if (remaining >  0) {
                cur = getCumulativeSum(startPos - remaining, i, csum);
            }
            ans = max(ans, cur);
        }
        return ans;
    }
private:
    int getCumulativeSum(int st, int ed, vector<int> &csum) {
        ed = min(ed, (int)csum.size()-1);
        if (st > 0) {
            return csum[ed] - csum[st - 1];
        } else {
            return csum[ed];
        }
    }
};