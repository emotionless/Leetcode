class Solution {
public:

    int profit(int p) {
        if (pos.find(p) != pos.end()) return 1;
        return 0;
    }

    int solve(int ind, int targetIndex, string &str, string &tar) {
        if (ind == str.length()) {
            if (targetIndex == tar.length()) {
                return 0;
            }
            return -INF;
        }
        int &ret = dp[ind][targetIndex];
        if (ret != -1) return ret;
        ret = -INF;
        // delete on all cases
        ret = profit(ind) + solve(ind + 1, targetIndex, str, tar);
        // dont delete on equalities
        if (targetIndex < tar.size() && str[ind] == tar[targetIndex]) {
            ret = max(ret, solve(ind + 1, targetIndex + 1, str, tar));
        }
        // cout << ind << " " << targetIndex << " " << ret << endl;

        return ret;
    }

    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        int n1 = source.size();
        int n2 = pattern.size();
        dp.resize(n1, vector<int>(n2 + 1, -1));
        for (auto ind : targetIndices) {
            pos.insert(ind);
        }
        int ans = solve(0, 0, source, pattern);
        return ans;
    }
private:
    const int INF = 1000000;
    vector<vector<int>> dp;
    unordered_set<int> pos;
};