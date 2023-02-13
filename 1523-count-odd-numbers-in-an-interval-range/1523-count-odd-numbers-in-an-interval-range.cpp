class Solution {
public:
    int countOdds(int low, int high) {
        if (low % 2 == 0) low++;
        if (low > high) return 0;
        return (high - low) / 2 + 1;
    }
};