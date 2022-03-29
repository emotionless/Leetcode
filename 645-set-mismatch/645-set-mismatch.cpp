class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }
        for (auto &v : nums) {
            sum ^= v;
        }
        int pos = 0;
        for (int i = 0; i < 31; i++) {
            if (sum&(1<<i)) {
                pos = i;
                break;
            }
        }
        int a = 0, b = 0;
        for (auto &v : nums) {
            if (v&(1<<pos)) {
                a ^= v;
            } else {
                b ^= v;
            }
        }
        for (int i = 0; i < n; i++) {
            if (b == nums[i]) {
                swap(a, b);
                break;
            }
        }
        return {a, b};
    }
};