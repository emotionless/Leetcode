class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int person = 0, cnt = 0;
        for (auto num : nums) {
            if (cnt == 0) {
                cnt++;
                person = num;
            } else {
                if (person == num) {
                    cnt++;
                } else {
                    cnt--;
                }
            }
        }
        return person;
    }
};