class Solution {
public:
    
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int n = aliceArrows.size();
        int ans = 0;
        int number = -1;
        for (int i = 0; i < (1<<n); i++) {
            int sum = 0;
            int score = 0;
            for (int j = 0; j < n; j++) {
                if (i&(1<<j)) {
                    sum += aliceArrows[j] + 1;
                    score += j;
                }
            }
            if (sum <= numArrows) {
                if (score > ans) {
                    ans = score;
                    number = i;
                }
            }
        }
        vector<int> ret(n, 0);
        for (int i = 0; i < n; i++) {
            if (number&(1<<i)) {
                ret[i] = aliceArrows[i] + 1;
                numArrows -= (aliceArrows[i] + 1);
            }
        }
        ret[11] += numArrows;
        
        return ret;
    }
};