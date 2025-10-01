class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total = numBottles;
        int empty = numBottles;
        while (empty >= numExchange) {
            int can = empty / numExchange;
            total += can;
            empty = can + empty - (empty / numExchange) * numExchange;
        }
        return total;
    }
};