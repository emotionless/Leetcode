class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bitset<20001> mask;
        mask = 1;
        int sum = 0;
        for (auto num : nums) {
            sum += num;
            mask |= (mask<<num);
        }
        return sum%2==0 && mask[sum/2];
    }
};