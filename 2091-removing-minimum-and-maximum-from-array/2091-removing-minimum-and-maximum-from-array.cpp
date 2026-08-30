class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mid = n/2;
        auto minelement = min_element(nums.begin(),nums.end());
        auto maxelement = max_element(nums.begin(),nums.end());
        int st = minelement - nums.begin();
        int ed = maxelement - nums.begin();
        if (st >= mid && ed >= mid) return max(n - st, n - ed);
        else if (st <= mid && ed <= mid) return 1 + max(st, ed);
        else return min(min(min(n - st, st + 1) + min(n - ed, ed + 1), n - min(st, ed)), 1 + max(st, ed));
    }
};