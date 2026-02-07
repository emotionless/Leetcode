class Solution {
public:
    int minimumDeletions(string s) {
        int len = s.length();
        vector<int> aCnter;
        aCnter.resize(len+1, 0);
        for(int i = len - 1; i >= 0; i--) {
            aCnter[i] = aCnter[i+1] + (s[i] == 'a'? 1 : 0);
        }
        int cnter = 0;
        int ans = aCnter[0];
        for(int i = 0; i < len; i++) {
            cnter += (s[i] == 'b'? 1 : 0);
            ans = min(ans, aCnter[i+1] + cnter);
        }
        return ans;
    }
};