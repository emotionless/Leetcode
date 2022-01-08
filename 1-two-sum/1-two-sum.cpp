class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>ret;
        map<int, int>M;
        for(int i = 0; i < n; i++)
        {
            int rest = target - nums[i];
            if(M.find(rest) != M.end())
            {
                ret.push_back(M[rest]);
                ret.push_back(i);
                return ret;
            }
            M[ nums[i] ] = i;
        }
        assert(0);
    }
};