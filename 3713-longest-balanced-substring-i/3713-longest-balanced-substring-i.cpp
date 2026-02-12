class Solution {
public:
    int longestBalanced(string s) {
        int ans = 1, n = s.length();
        // case 1 : "abcabc"
        map<pair<int,int> ,int> mp;
        mp[{0,0}] = -1;
        int v1 = 0, v2 = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'a')v1++;
            else if(s[i] == 'b')v2++;
            else if(s[i] == 'c'){
                v1--;
                v2--;
            }
            if(mp.find({v1,v2}) == mp.end())mp[{v1,v2}] = i;
            else ans = max(ans, i - mp[{v1,v2}]);
        }

        // case 2 : "abcbcbcbc"
        vector<string> comb = {"ab", "bc", "ac"};
        for(auto &t : comb){
            unordered_map<int,int> m;
            m[0] = -1;
            int v = 0;
            for(int i = 0; i < n; i++){
                if(s[i] == t[0])v++;
                else if(s[i] == t[1])v--;
                else{
                    v = 0;
                    m.clear();
                }
                if(m.find(v) == m.end())m[v] = i;
                else ans = max(ans, i - m[v]);
            }
        }

        // case 3 : "aaaaaaaaaaaaabc"
        int cnt = 1;
        for(int i = 1; i < n; i++){
            if(s[i] == s[i-1])cnt++;
            else cnt = 1;
            ans = max(ans, cnt);
        }
        return ans;
    }
};