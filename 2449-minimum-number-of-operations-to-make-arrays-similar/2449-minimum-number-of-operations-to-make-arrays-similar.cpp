class Solution {
public:
    struct comparator {
        bool operator() (const int &num1, const int &num2) {
            if (num1%2 == num2%2) return num1 < num2;
            return num1%2 < num2%2;
        }
    };
    
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        sort(nums.begin(), nums.end(), comparator());
        sort(target.begin(), target.end(), comparator());
        int n = nums.size();
        long long tot = 0;
        for (int i = 0; i < n; i++) {
            tot += abs(nums[i] - target[i]);
        }
        return tot/4;
    }
};