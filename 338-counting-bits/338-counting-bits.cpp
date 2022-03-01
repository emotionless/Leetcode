class Solution {
public:
    int numberOfBits(int n) {
        int ret = 0;
        while (n) {
            ret += n%2;
            n /= 2;
        }
        return ret;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for (int i = 0; i <= n; i++) {
            ans.push_back(numberOfBits(i));
        }
        return ans;
    }
};