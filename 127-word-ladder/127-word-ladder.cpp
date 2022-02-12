class Solution {
public:
    
    bool isOneDiff(string str1, string str2) {
        if(str1.length() != str2.length()) return false;
        int len = str1.length();
        int cnt = 0;
        for(int i = 0; i < len; i++) {
            if(str1[i] != str2[i]) cnt++;
            if(cnt > 1) return false;
        }
        return cnt == 1;
    }
    
    int solve(string cur, const string endWord, vector<string> wordList) {
        int n = wordList.size();
        queue<int> Q;
        vector<int> cost(n, -1);
        vector<bool>vis(n, false);
        
        for(int i = 0; i < n; i++) {
            if(isOneDiff(cur, wordList[i])) {
                Q.push(i);
                cost[i] = 2;
                vis[i] = true;
            }
        }
        while(!Q.empty()) {
            int curInd = Q.front();
            Q.pop();
            if(endWord == wordList[curInd]) return cost[curInd];
            for(int i = 0; i < n; i++) {
                if(!vis[i] && isOneDiff(wordList[curInd], wordList[i])) {
                    cost[i] = cost[curInd] + 1;
                    vis[i] = true;
                    Q.push(i);
                }
            }
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord.length() != endWord.length()) return 0;
       return solve(beginWord, endWord, wordList);
    }
};