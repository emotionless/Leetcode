class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int cnt = 0;
        for (auto fruit : fruits) {
            for (auto &basket : baskets) {
                if (basket >= fruit) {
                    basket = 0;
                    cnt++;
                    break;
                }
            }
        }
        return baskets.size() - cnt;
    }
};