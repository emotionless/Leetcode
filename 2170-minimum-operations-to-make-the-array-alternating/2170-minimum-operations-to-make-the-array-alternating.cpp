class Solution {
public:
    
    struct comparator {
        bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
            if (a.second == b.second) -a.second < -b.second;
            return -a.first < -b.first;
        }
    };
    
    pair<pair<int, int>, pair<int, int>> getTwoLargeNumber(unordered_map<int, int> &counter) {
        pair<int, int> first({0, 0}), second({0, 0});
        for (auto ele : counter) {
            if (ele.second > first.second) {
                second = first;
                first = make_pair(ele.first, ele.second);
            } else if (ele.second >= second.second) {
                second = make_pair(ele.first, ele.second);
            }
        }
        return {first, second};
    }
    
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> counter;
        for (int i = 0; i < n; i+=2) {
            counter[nums[i]]++;
        }
        auto firstTwo = getTwoLargeNumber(counter);
        counter.clear();
        for (int i = 1; i < n; i+=2) {
            counter[nums[i]]++;
        }
        auto secondTwo = getTwoLargeNumber(counter);
        
        int ans = n;
        if (firstTwo.first.first != secondTwo.first.first) {    // 1 1
            ans = min(ans, n - firstTwo.first.second - secondTwo.first.second);
        }
        if (firstTwo.first.first != secondTwo.second.first) {   // 1 2
            ans = min(ans, n - firstTwo.first.second - secondTwo.second.second);
        }
        if (firstTwo.second.first != secondTwo.first.first) {   // 2 1
            ans = min(ans, n - firstTwo.second.second - secondTwo.first.second);
        }
        if (firstTwo.second.first != secondTwo.second.first) {  // 2 2
            ans = min(ans, n - firstTwo.second.second - secondTwo.second.second);
        }
        return ans;
    }
};