class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans;
        ans.resize(n);
        int ind = 0;
        while (n--) {
            int can = max(1, k - n*26);
            ans[ind++] += (char)(can - 1 + 'a');
            k -= can;
        }
        return ans;
    }
};