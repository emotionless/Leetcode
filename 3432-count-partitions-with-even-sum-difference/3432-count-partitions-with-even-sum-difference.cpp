class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int num : nums) sum += num;
        int count = 0;
        int csum = 0;
        for (auto num : nums) {
            csum += num;
            sum -= num;
            if (abs(csum - sum) %2 == 0 && sum > 0) count++;
        }
        return count;
    }
};