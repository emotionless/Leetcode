class Solution {
public:
    int getP(int st, int ed, vector<int> &nums) {
        for (int i = st + 1; i < ed; i++) {
            if (nums[i] <= nums[i-1]) return -1;
            if (nums[i] > nums[i-1] && nums[i] > nums[i+1]) return i;
        }
        return -1;
    }

    int getQ(int st, int ed, vector<int> &nums) {
        for (int i = st + 1; i < ed; i++) {
            if (nums[i] >= nums[i-1]) return -1;
            if (nums[i] < nums[i-1] && nums[i] < nums[i+1]) return i;
        }
        return -1;
    }

    bool isIncreasing(int st, int ed, vector<int> &nums) {
        for (int i = st + 1; i <= ed; i++) {
            if (nums[i] <= nums[i-1]) return false;
        }
        return true;
    }

    bool isDecreasing(int st, int ed, vector<int> &nums) {
        for (int i = st + 1; i <= ed; i++) {
            if (nums[i] >= nums[i-1]) return false;
        }
        return true;
    }
    

    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int p = getP(0, n-1, nums);
        if (p == -1) return false;
        int q = getQ(p, n-1, nums);
        // cout << q << endl;
        if (q == -1) return false;
        // cout << p << " " << q << endl;
        if (isIncreasing(0, p, nums) && isDecreasing(p, q, nums) && isIncreasing(q, n-1, nums)) return true;
        return false;
        
    }
};