class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> winner, loser;
        for (auto &v : matches) {
            winner[v[0]]++;
            loser[v[1]]++;
        }
        vector<int> list1, list2;
        for (auto &v : winner) {
            if (loser[v.first] == 0) {
                list1.push_back(v.first);
            }
        }
        for (auto &v : loser) {
            if (v.second == 1) {
                list2.push_back(v.first);
            }
        }
        
        sort(list1.begin(), list1.end());
        sort(list2.begin(), list2.end());
        return {list1, list2};
    }
};