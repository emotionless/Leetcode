class Solution {
public:
    vector<int> prime{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113};
    const int MOD = 1e9 + 7;
    long long getHash(const string &str) {
        long long hash = 1;
        for (auto ch : str) {
            hash = (hash * prime[ch - 'a']) % MOD;
        }
        return hash;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<long long, vector<string>> hash;
        for (auto str : strs) {
            long long h = getHash(str);
            hash[h].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto ele : hash) {
            ans.push_back(ele.second);
        }
        return ans;
    }
};