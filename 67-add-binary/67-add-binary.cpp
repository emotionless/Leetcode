class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size(), j = b.size();
        string ans = "";
        int carry = 0;
        i--, j--;
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