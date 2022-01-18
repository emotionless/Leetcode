class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> ans(n, 0);
        sort(deck.begin(), deck.end());
        int ind = 1;
        int cnt = 2;
        for (auto v : deck) {
            while (cnt <= 1) {
                if (ans[ind] == 0) {
                    cnt++;
                }
                ind++;
                ind %= n;
            }
            ans[(ind - 1 + n)%n] = v;
            cnt = 0;
        }
        return ans;
    }
};