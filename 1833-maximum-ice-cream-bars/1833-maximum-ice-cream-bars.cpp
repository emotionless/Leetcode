class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        long long sum = accumulate(costs.begin(), costs.end(), 0ll);
        int j = costs.size() - 1;
        while (j >= 0 && sum > coins) {
            sum -= costs[j--];
        }
        return j+1;
    }
};