class Solution {
public:
    int getCount(string &message) {
        stringstream ss;
        ss<<message;
        string str;
        int cnt = 0;
        while (ss >> str) {
            cnt++;
        }
        return cnt;
    }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> messageCount;
        int n = senders.size();
        int mx = 0;
        string ans = "";
        for (int i = 0; i < n; i++) {
            messageCount[senders[i]] += getCount(messages[i]);
            int cnt = messageCount[senders[i]];
            if (cnt == mx) {
                ans = max(ans, senders[i]);
            } else if (cnt > mx) {
                ans = senders[i];
                mx = cnt;
            }
        }
        return ans;
    }
};