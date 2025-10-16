class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n =  nums.size();
        unordered_map<int, int> counter;
        for (auto num : nums) {
            num = ((num%value) + value) % value;
            counter[num]++;
        }
        int ans = n;
        for (int i = 0; i < n; i++) {
            int times = counter[i%value];
            // cout << i << " " << times  << endl;
            ans = min(ans, i + value*times);
        }
        return ans;
    }
};