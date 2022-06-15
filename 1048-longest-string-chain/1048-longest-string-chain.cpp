// NOTE: This code is just for practing hash method by own hand
// I can do it in better way

class Solution {
public:
    const int MOD = 1000091;
    const int base = 19;
    
    int hash(string &str) {
        int sum = 0;
        int mul = 1;
        srand(time(NULL));
        int len = str.length();
        for (int i = 0; i < len; i++) {
            sum = (sum + (mul * str[i]) % MOD) % MOD;
            mul = (mul * base) % MOD; 
        }
        return sum;
    }
    
    bool isChain(string &str1, string &str2) {
        if ((str2.length() - 1) != str1.length()) return false;
        bool ck = false;
        for (int i = 0, j = 0; i < str1.length(); i++, j++) {
            if (str1[i] != str2[j]) {
                if (ck) return false;
                i--;
                ck = true;
            }
        }
        return true;
    }
    
    int solve(int cur) {
        // cout << cur << endl;
        int &ret = dp[cur];
        if (ret != -1) return ret;
        ret = 0;
        for (auto v : adj[cur]) {
            ret = max(ret, solve(v));
        }
        return ret = ret + 1;
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        int mx = 0;
        for (auto v : words) {
            mx = max(mx, hash(v));
        }
        adj.clear();
        adj.resize(mx + 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (isChain(words[i], words[j])) {
                    adj[hash(words[i])].push_back(hash(words[j]));
                }
            }
        }
        dp.clear();
        dp.resize(mx + 1, -1);
        int ans = 0;
        for (auto str : words) {
            // cout << hash(str) << endl;
            ans = max(ans, solve(hash(str)));
            // cout << endl;
        }
        return ans;
    }
private:
    vector<int> dp;
    vector<vector<int>> adj;
};