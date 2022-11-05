class Solution {
public:
    long long numberOfSteps(vector<int> &list1, vector<int> &list2) {
        sort(list1.begin(), list1.end());
        sort(list2.begin(), list2.end());
        int n = list1.size();
        int carry = 0;
        long long steps = 0;
        for (int i = 0; i < n; i++) {
            int diff = abs(list1[i] - list2[i]);
            steps += diff;
        }
        return steps/2;
    }
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<int> odd1, even1;
        vector<int> odd2, even2;
        for (auto &num : nums) {
            if (num&1) odd1.push_back(num);
            else even1.push_back(num);
        }
        for (auto &num : target) {
            if (num&1) odd2.push_back(num);
            else even2.push_back(num);
        }
        return (numberOfSteps(odd1, odd2) + numberOfSteps(even1, even2))/2;
    }
};