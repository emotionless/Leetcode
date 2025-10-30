class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        /*
        int n = target.size();
        int com = 1;
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({target[i], i});
        }
        sort(arr.begin(), arr.end());
        int last = 0;
        int ans = 0;
        for (auto ele : arr) {
            int num = ele.first;
            int pos = ele.second;
            ans += (num - last) * com;
            last = num;
            int cnt = 0;
            if (pos == 0) cnt++;
            else if (target[pos-1] == -1) cnt++;
            
            if ((pos+1) == n) cnt++;
            else if (target[pos+1] == -1) cnt++;
            
            if (cnt == 2) {
                com--;
            } else if (cnt == 0) {
                com++;
            }
            target[pos] = -1;
        }
        return ans;
        */
        int ans = 0;
        int pre = 0;
        for (auto v : target) {
            if (v > pre) ans += v - pre;
            pre = v;
        }
        return ans;
    }
};