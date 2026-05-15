class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int st = 0, ed = n-1, mid, ans = 0;
        int cnt = 0;
        while(cnt < 50)
        {
            cnt++;
            mid = (st+ed)>>1;
            if(nums[mid] < nums[ed])
            {
                ans = mid;
                ed = mid;
            }
            else if(nums[mid] > nums[st])
            {
                if(nums[st] < nums[ans])
                    ans = st;
                st = mid;
            }
            
            else
            {
                if(nums[st] < nums[ans])
                    ans = st;
                if(nums[ed] < nums[ans])
                    ans = ed;
                if(st < ed && nums[st+1] >= nums[st])
                    st++;
                if(ed > st && nums[ed-1] <= nums[ed])
                    ed--;
            }
        }
        return nums[ans];
    }
};