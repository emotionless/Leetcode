class Solution {
public:
    
    string say(string str) {
        int cnt = 1;
        string ret = "";
        int len = str.size();
        for (int i = 1; i < len; i++) {
            if (str[i] == str[i-1]) cnt++;
            else {
                ret += to_string(cnt) + str[i-1];
                cnt = 1;
            }
        }
        ret += to_string(cnt) + str[len - 1];
        
        return ret;
    }
    
    string countAndSay(int n) {
        string ans = "1";
        for (int i = 2; i <= n; i++) {
            ans = say(ans);
        }
        return ans;
    }
};