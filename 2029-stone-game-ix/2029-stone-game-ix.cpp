class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int counter[3] = {0};
        for (auto stone : stones) {
            int dividend = stone % 3;
            counter[dividend]++;
        }
        if (counter[0]%2 == 0) {
            return counter[1] > 0 && counter[2] > 0;
        }
        return abs(counter[1] - counter[2]) > 2;
    }
};