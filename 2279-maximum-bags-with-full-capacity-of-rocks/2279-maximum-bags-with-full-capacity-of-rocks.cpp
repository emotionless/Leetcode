class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> arr;
        for (int i = 0; i < capacity.size(); i++) {
            arr.push_back(capacity[i] - rocks[i]);
        }
        sort(arr.begin(), arr.end());
        
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > additionalRocks) return i;
            additionalRocks -= arr[i];
        }
        return arr.size();
    }
};