class Solution {
public:
    
    bool canReachZero(int ind, vector<int> &arr) {
        queue<int> q;
        q.push(ind);
        dp[ind] = true;
        
        while (!q.empty()) {
            int cn = q.front();
            q.pop();
            
            if (arr[cn] == 0) {
                return true;
            }
            if ((cn + arr[cn]) < arr.size() && dp[cn+arr[cn]] == false) {
                dp[cn+arr[cn]] = true;
                if ((arr[cn+arr[cn]]) == 0) return true;
                q.push(cn+arr[cn]);
            }
            if ((cn - arr[cn]) >= 0 && dp[cn-arr[cn]] == false) {
                dp[cn-arr[cn]] = true;
                if ((arr[cn-arr[cn]]) == 0) return true;
                q.push(cn-arr[cn]);
            }
        }
        return false;
    }
    
    bool canReach(vector<int>& arr, int start) {
        dp.resize(arr.size(), false);
        return canReachZero(start, arr);
    }
private:
    vector<bool> dp;
};