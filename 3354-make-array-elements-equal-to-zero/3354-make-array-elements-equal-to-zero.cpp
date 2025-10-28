class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int sum = 0;
        for (auto &num : nums) sum += num;
        int csum = 0;
        int cnt = 0;
        for (auto &num : nums) {
            csum += num;
            if (num == 0 && csum*2 == sum) {
                cnt+=2;
            } else if (num == 0 && abs(sum - 2*csum) <= 1) {
                cnt++;
            }
        }
        return cnt;
    }
};