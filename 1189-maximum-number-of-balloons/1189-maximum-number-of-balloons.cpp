class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> frequency;
        for (auto ch : text) {
            frequency[ch]++;
        }
        int ans = frequency['b'];
        ans = min(ans, frequency['a']);
        ans = min(ans, frequency['l']/2);
        ans = min(ans, frequency['o']/2);
        ans = min(ans, frequency['n']);
        return ans;
    }
};