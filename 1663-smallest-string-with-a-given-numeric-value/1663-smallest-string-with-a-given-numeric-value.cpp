class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans = "";
        while (n--) {
            int can = max(1, k - n*26);
            ans += (char)(can - 1 + 'a');
            k -= can;
        }
        return ans;
    }
};