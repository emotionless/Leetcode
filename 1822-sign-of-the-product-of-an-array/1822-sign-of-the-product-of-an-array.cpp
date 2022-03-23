class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count = 0;
        for (auto num : nums) {
            if (num == 0) return 0;
            else if (num < 0) count++;
        }
        return count&1? -1 : 1;
    }
};