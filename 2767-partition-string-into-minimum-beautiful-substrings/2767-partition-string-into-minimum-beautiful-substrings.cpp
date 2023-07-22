class Solution {
public:
    const int INF = 100000;
    int convertIntoInt(string &s, int st, int ed) {
        int num = 0;
        int mul = 1;
        for (int i = ed; i >= st; i--) {
            num += (s[i] - '0') * mul;
            mul *= 2;
        }
        return num;
    }
    
    bool powerOfX(int num, int d) {
        if (num == 0) return false;
        while (num > 1 && num%d == 0) {
            num /= d;
        }
        return num == 1;
    }
    
    int solve(int ind, string &s) {
        if (ind == s.size()) return 0;
        if (s[ind] == '0') return INF;
        int &ret = dp[ind];
        if (ret != -1) return ret;
        ret = INF;
        for (int i = ind; i < s.size(); i++) {
            int num = convertIntoInt(s, ind, i);
            if (powerOfX(num, 5)) {
                ret = min(ret, 1 + solve(i + 1, s));
            }
        }
        return ret;
    }
    
    int minimumBeautifulSubstrings(string s) {
        dp.resize(s.size(), -1);
        int ans = solve(0, s);
        if (ans >= INF) return -1;
        return ans;
    }
private:
    vector<int> dp;
};