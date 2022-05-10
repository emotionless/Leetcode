class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> pos;
        int n = cards.size();
        int ans = n + 2;
        for (int i = 0; i < n; i++) {
            if (pos.find(cards[i]) != pos.end()) {
                ans = min(ans, i - pos[cards[i]]);
                if (ans == 1) return 2;
            } 
            pos[cards[i]] = i;
        }
        if (ans > n) return -1;
        return ans + 1;
    }
};