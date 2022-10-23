class Solution {
public:
    
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> messageCount;
        int n = senders.size();
        int mx = 0;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            int cnt = messageCount[senders[i]] += count(begin(messages[i]), end(messages[i]), ' ') + 1;
            if (cnt > mx || (cnt == mx && senders[i] > senders[ans])) {
                ans = i;
                mx = cnt;
            }
        }
        return senders[ans];
    }
};