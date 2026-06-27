class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int, int> counter;
        unordered_set<long long> vis;
        for (auto num : nums) {
            counter[num]++;
        }
        int mx = 0;
        int one = 0;
        for (long  long num : nums) {
            if (num == 1) {
                one+=1;
                continue;
            }
            // if (vis.contains(num)) continue;
            int cnt = 0;
            while (num <= 1e9 && counter[num] >= 2) {
                num *= num;
                cnt++;
                // vis.insert(num);
            }
            if (counter[num] == 1) cnt++;
            mx = max(mx, cnt);
        }
        if (one%2==0) one--;
        return max(one, mx + mx - 1);
    }
};