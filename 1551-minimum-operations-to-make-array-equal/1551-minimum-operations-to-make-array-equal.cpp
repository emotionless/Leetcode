class Solution {
public:
    int minOperations(int n) {
        int st = 1, ed = n*2 - 1;
        int target = (st + ed) / 2;
        int sum = 0;
        for (int i = 1; i <= target; i+=2) {
            sum += target - i;
        }
        return sum;
    }
};