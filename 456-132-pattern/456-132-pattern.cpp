class Solution {
public:
    
    /*
    
    3 1 4 2
    
    
    */
    
    bool find132pattern(const vector<int>& nums) {
        vector<int> mn;
        int n = nums.size();
        mn.resize(nums.size());
        if (nums.size() < 3) return false;
        mn[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            mn[i] = min(mn[i-1], nums[i-1]);
        }
        stack<int> container;
        container.push(nums[n-1]);
        for(int i = n - 2; i > 0; i--) {
            while(container.size() > 0) {
                if (container.top() <= mn[i]) container.pop();
                else break;
            }
            if (container.size() > 0 && container.top() < nums[i]) {
                return true;
            }
            container.push(nums[i]);
        }
        return false;
    }
};