class Solution {
public:
    int sod(int num) {
        int d = 0;
        while  (num > 0) {
            d += num%10;
            num /= 10;
        }
        return d;
    }
    int minElement(vector<int>& nums) {
        int ans  = 100;
        for  (auto  num :  nums) {
            ans = min(ans, sod(num));
        }
        return ans;
    }
};