class Solution {
public:
    
    void generate(int base, int low, int high, vector<int> &ans) {
        int num = base;
        if (num >= low && num <= high) {
            ans.push_back(num);
        }
        int last = base;
        while (num < high && last < 9) {
            num *= 10;
            last++;
            num += last;
            if (num >= low && num <= high) {
                ans.push_back(num);
            }
        }
        return;
    }
    
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for (int i = 1; i < 10; i++) {
            generate(i, low, high, ans);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};