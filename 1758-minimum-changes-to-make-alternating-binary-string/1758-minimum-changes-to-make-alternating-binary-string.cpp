class Solution {
public:
    int minOperations(string s) {
        int len = s.size();
        int cnt1 = 0, cnt2 = 0;
        int now = 0;
        for (int i = 0; i <len;i++){
            int id = s[i] - '0';
            if(id == now) cnt1++;
            if(id != now) cnt2++;
            now = 1 - now;
            
        }
        return min(cnt1, cnt2);
    }
};