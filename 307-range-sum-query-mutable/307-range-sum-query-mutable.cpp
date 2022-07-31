class NumArray {
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        arr.resize(n, 0);
        sq = sqrt(n) + 1;
        groupSum.resize(sq + 1, 0);
        for (int i = 0; i < n; i++) {
            arr[i] = nums[i];
            groupSum[i/sq] += nums[i]; 
        }
    }
    
    void update(int index, int val) {
        int old = arr[index];
        groupSum[index/sq] += (val - old);
        arr[index] = val;
    }
    
    int sumRange(int left, int right) {
        int lg = left/sq, rg = right/sq;
        int sum = 0;
        if (lg == rg) {
            for (int i = left; i <= right; i++) sum += arr[i];
            return sum;
        }
        for (int i = left; i < (lg+1)*sq; i++) {
            sum += arr[i];
        }
        for (int i = (rg) * sq; i <= right; i++) {
            sum += arr[i];
        }
        for (int i = lg + 1; i < rg; i++) {
            sum += groupSum[i];
        }
        return sum;
    }
private:
    vector<int> arr, groupSum;
    int n, sq;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */