class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        map<int, int> counter;
        vector<pair<int, int>> people;
        int sz = persons.size();
        for (int i = 0; i < sz; i++) {
            counter[persons[i]] = 0;
            people.push_back({persons[i], i});
        }
        for (auto &flower : flowers) {
            counter[flower[0]]++;
            counter[flower[1] + 1]--;
        }
        
        sort(people.begin(), people.end());
        int total = 0;
        vector<int> ans(sz, 0);
        int ind = 0;
        for (auto &it : counter) {
            total += it.second;
            while (ind < sz && people[ind].first == it.first) {
                ans[people[ind].second] = total;
                ind++;
            }
        }
        return ans;
    }
};