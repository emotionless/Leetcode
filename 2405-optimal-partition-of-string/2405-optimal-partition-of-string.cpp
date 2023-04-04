class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> vis;
        int cnt = 1;
        for (auto &ch : s) {
            if (vis.find(ch) != vis.end()) {
                cnt++;
                vis.clear();
            }
            vis.insert(ch);
        }
        return cnt;
    }
};