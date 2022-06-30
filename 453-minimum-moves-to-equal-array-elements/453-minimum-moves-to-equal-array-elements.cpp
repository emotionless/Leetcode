class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long sum = accumulate(nums.begin(), nums.end(), 0);
        long long minNum = *min_element(nums.begin(), nums.end());
        return sum - minNum * (nums.size());
    }
};