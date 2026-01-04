class Solution {
public:
    int isFourDivisors(int num) {
        int sq = sqrt(num);
        if (sq*sq ==  num) return -1;
        int cnt = 0;
        int ans = -1;
        for (int i  = 2;  i  <= sq;  i++) {
            if (num%i==0) {
                ans = i;
                cnt++;
            }
        }
        if (cnt > 1) return -1;
        return ans;
    }
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for (auto   num : nums) {
            int sod = isFourDivisors(num);
            if (sod != -1) {
                sum += num + 1;
                sum += sod;
                sum += num/sod;
            }
        }
        return sum;
    }
};