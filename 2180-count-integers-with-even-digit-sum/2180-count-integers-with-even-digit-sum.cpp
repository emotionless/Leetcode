class Solution {
public:
    
    int getSum(int num) {
        int ret = 0;
        while (num) {
            ret += num%10;
            num /= 10;
        }
        return ret;
    }
    
    int countEven(int num) {
        int div = num / 20;
        int ans = 0;
        ans += div * 10;
        for (int i = div*20; i <= num; i++) {
            int sum = getSum(i);
            ans += (sum%2==0?1:0);
        }
        return ans - 1;
    }
};