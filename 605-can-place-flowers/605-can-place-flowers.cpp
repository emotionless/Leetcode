class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        int sum = 1;
        int tot = 0;
        for (int i = 0; i < m; i++) {
            if (flowerbed[i] == 0) sum++;
            else {
                tot += (sum-1)/2;
                sum = 0;
            }
        }
        sum++;
        tot += (sum-1)/2;
        return tot >= n;
    }
};