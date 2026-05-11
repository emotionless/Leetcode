class Solution {
public:
    
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(auto num : nums) {
            vector<int> tmp;
            while (num) {
                tmp.push_back(num%10);
                num /= 10;
            }
            for (int i = tmp.size() - 1; i >= 0; i--) {
                ans.push_back(tmp[i]);
            }
        }
        return ans;
    }
};