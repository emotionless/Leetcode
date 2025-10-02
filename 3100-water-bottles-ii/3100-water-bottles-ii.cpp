class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int total = numBottles;
        int empty = numBottles;
        while (empty >= numExchange) {
            empty-=numExchange;
            total++;
            empty+=1;
            numExchange++;
        }
        return total;
    }
};