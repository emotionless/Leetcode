class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int allXor = 0;
        for (int i = 1; i <= n; i++) {
            allXor ^= i;
        }
        int sum = allXor;
        for (auto &num : nums) {
            sum ^= num;
        }
        int firstBit = 0;
        for (int i = 0; i < 31; i++) {
            if (sum&(1<<i)) {
                firstBit = i;
                break;
            }
        }
        int firstBox = 0;
        for (int i = 1; i <= n; i++) {
            if (i&(1<<firstBit)) {
                firstBox ^= i;
            }
        }
        int lastBox = allXor ^ firstBox;
        for (auto &num : nums) {
            if (num&(1<<firstBit)) {
                firstBox ^= num;
            } else {
                lastBox ^= num;
            }
        }
        for (auto &num : nums) {
            if (num == firstBox) {
                return {firstBox, lastBox};
            }
        }
        return {lastBox, firstBox};
    }
};