class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum&1) return {};
        long long sum = 0;
        int num = 0;
        while (sum <= finalSum) {
            num += 2;
            sum += num;
        }
        long long extra = sum - finalSum;
        vector<long long> ans;
        for (int i = 2; i <= num; i+=2) {
            if (i == extra) continue;
            ans.push_back(i);
        }
        return ans;
    }
};