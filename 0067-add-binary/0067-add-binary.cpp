class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        string ans = "";
        int carry = 0;
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = (i >= 0? (a[i]-'0') : 0) + (j >= 0? (b[j]-'0') : 0) + carry;
            carry = sum / 2;
            sum %= 2;
            ans += to_string(sum);
            i--, j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};