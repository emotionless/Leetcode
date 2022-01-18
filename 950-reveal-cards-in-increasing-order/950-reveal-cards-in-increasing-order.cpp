class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> ans(n, 0);
        sort(deck.begin(), deck.end());
        deque<int> q;
        for (int i = 0; i < n; i++) {
            q.push_back(i);
        }
        for (auto v : deck) {
            auto top = q.front();
            q.pop_front();
            if (q.size()) {
                int repeat = q.front();
                q.pop_front();
                q.push_back(repeat);
            }
            ans[top] = v;
        }
        return ans;
    }
};