class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> map1, map2;
        unordered_set<int> allNums;

        for (auto num : basket1) {
            map1[num]++;
            allNums.insert(num);
        }
        for (auto num : basket2) {
            map2[num]++;
            allNums.insert(num);
        }
        vector<int> container;
        for (auto num : allNums) {
            if ((map1[num] + map2[num]) % 2) return -1;
            int cnt1 = map1[num];
            int cnt2 = map2[num];
            int mid = (cnt1 + cnt2) / 2;
            for (int i = min(cnt1, cnt2); i < mid; i++) {
                container.push_back(num);
            }
        }
        long long ans = 0;
        sort(container.begin(), container.end());
        for (int i = 0; i < container.size() / 2; i++) {
            ans += container[i];
        }
        return ans;
    }
};

/**
2 2 2 4
1 1 2 4


1 2 3 4
1 2 3 5

[3,4,4,4,4]
[3,5,5,5,5]

*/