class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for (auto num  : nums2) {
            counter[num]++;
        }
        num1Cpy = nums1;
        num2Cpy = nums2;
    }
    
    void add(int index, int val) {
        counter[num2Cpy[index]]--;
        num2Cpy[index] = num2Cpy[index] + val;
        counter[num2Cpy[index]]++;
    }
    
    int count(int tot) {
        int cnt = 0;
        for (int num : num1Cpy) {
            cnt += counter[tot - num];
        }
        return cnt;
    }

private:
    unordered_map<int, int> counter;
    vector<int> num1Cpy,  num2Cpy;
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */