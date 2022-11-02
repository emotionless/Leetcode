class Solution {
public:
    
    bool isOneDiff(string &str1, string &str2) {
        int cnt = 0;
        for (int i = 0; i < 8; i++) {
            if (str1[i] != str2[i]) cnt++;
        }
        return cnt <= 1;
    }
    
    int solve(int ind, string &end, vector<string> &bank) {
        if (bank[ind] == end) return 0;
        int &ret = dp[ind];
        if (ret != -1) return ret;
        ret = 1000;
        for (int i = 0; i < bank.size(); i++) {
            if (i != ind && isOneDiff(bank[i], bank[ind])) {
                ret = min(ret, 1 + solve(i, end, bank));
            }
        }
        return ret;
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
        dp.resize(bank.size(), -1);
        int res = 100;
        for (int i = 0; i < bank.size(); i++) {
            if (isOneDiff(bank[i], start)) {
                res = min(res, 1 + solve(i, end, bank));
            }
        }
        return res > 10 ? -1 : res;
    }
private:
    vector<int> dp;
};