class Solution {
public:
    
    string rev(string str) {
        reverse(str.begin(), str.end());
        
        return str;
    }
    
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> counter;
        for (auto &word : words) {
            counter[word]++;
        }
        int ans = 0;
        for (auto &word : words) {
            string r = rev(word);
            if (word == r && counter[word] == 1) continue;
            if (counter[word] > 0 && counter[r] > 0) {
                ans += 4;
                counter[word]--;
                counter[r]--;
            }
        }
        int mx = 0;
        for (char i = 'a'; i <= 'z'; i++) {
            string rev = "";
            rev += i;
            rev += i;
            mx = max(mx, 2*counter[rev]);
        }
        return mx + ans;
    }
};