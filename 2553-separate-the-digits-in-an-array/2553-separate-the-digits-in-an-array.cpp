class Solution {
public:
    
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(auto num : nums) {
            bool ck = false;
            if (num >= 100000) {
                ans.push_back(num/100000);
                num %= 100000;
                ck = true;
            }
            if (num >= 10000 || ck) {
                ans.push_back(num/10000);
                num %= 10000;
                ck = true;
            }
            if (num >= 1000 || ck) {
                ans.push_back(num/1000);
                num %= 1000;
                ck = true;
            }
            if (num >= 100 || ck) {
                ans.push_back(num/100);
                num %= 100;
                ck = true;
            }

            if (num >= 10 || ck) {
                ans.push_back(num/10);
                num %= 10;
                ck = true;
            }
            ans.push_back(num);
        }
        return ans;
    }
};