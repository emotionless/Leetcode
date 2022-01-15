class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        int num = 0, sum = 0, mx = 0;
        map<int, int> counter;
        int tot = n;
        for (int i = 0; i < n/2; i++) {
            int a = nums[i], b = nums[n - i - 1];
            counter[min(a,b) + 1]--;
            counter[a+b]--;
            counter[a+b+1] += 1;
            counter[max(a, b) + limit + 1] += 1;
        }
        int ans = tot;
        for (auto element : counter) {
            tot += element.second;
            // cout << element.first << " " << element.second << " " << tot << endl;
            ans = min(ans, tot);
        }
        return ans;
    }
};