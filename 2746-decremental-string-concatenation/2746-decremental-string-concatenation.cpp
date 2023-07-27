class Solution {
public:
    
    int solve(int ind, int first, int last, vector<string> &words) {
        if (ind == n) return 0;
        int &ret = dp[ind][first][last];
        if (ret != -1) return ret;
        int sz = words[ind].size();
        ret = (last == firstChar(words[ind])? (sz - 1) : sz) + solve(ind + 1, first, lastChar(words[ind]), words);
        ret = min(ret, (first == (lastChar(words[ind]))? (sz - 1) : sz) + solve(ind + 1, firstChar(words[ind]), last, words));
        return ret;
    }
    
    int minimizeConcatenatedLength(vector<string>& words) {
        n = words.size();
        dp.resize(n, vector<vector<int>> (26, vector<int>(26, -1)));
        return words[0].size() + solve(1, firstChar(words[0]), lastChar(words[0]), words);
    }
    
    int lastChar(string &str) {
        return str[str.size() - 1] - 'a';
    }
    
    int firstChar(string &str) {
        return str[0] - 'a';
    }
    
private:
    int n;
    vector<vector<vector<int>>> dp;
};