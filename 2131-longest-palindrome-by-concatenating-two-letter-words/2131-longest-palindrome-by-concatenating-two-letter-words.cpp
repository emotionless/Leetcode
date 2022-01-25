class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int sum = 0;
        unordered_map<string, int> counter;
        for (auto word : words) {
            string rev = "";
            rev += word[1];
            rev += word[0];
            counter[word]++;
        }
        for (auto word : words) {
            string rev = "";
            rev += word[1];
            rev += word[0];
            if (word == rev) continue;
            if (counter[word] > 0 && counter[rev] > 0) {
                sum += 4;
                counter[word] -= 1;
                counter[rev] -= 1;
            }
        }
        int mx = 0;
        for (char i = 'a'; i <= 'z'; i++) {
            string rev = "";
            rev += i;
            rev += i;
            mx = max(mx, counter[rev]%2);
            if (counter[rev] > 0) {
                sum += (counter[rev]/2)*4;
            }
        }
        return sum + mx * 2;
    }
};