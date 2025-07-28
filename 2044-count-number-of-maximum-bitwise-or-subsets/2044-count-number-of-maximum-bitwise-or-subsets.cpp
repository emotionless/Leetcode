class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n =  nums.size();
        int counter = 0;
        int mx = 0;
        for (int i = 1; i < (1<<n); i++){
            int sum = 0;
            for (int j = 0; j < n; j++) {
                if (i&(1<<j)) {
                    sum = sum | nums[j];
                }
            }
            if (sum > mx) {
                mx = sum;
                counter = 1;
            } else if (sum == mx) {
                counter++;
            }
        }
        return counter;
    }
};