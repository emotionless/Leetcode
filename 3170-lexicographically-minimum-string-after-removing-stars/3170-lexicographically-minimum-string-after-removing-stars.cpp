class Solution {
public:

    struct node {
        char ch;
        int pos;
        node(char _ch, int _pos) {
            ch = _ch;
            pos = _pos;
        }
    };
    struct Compare {
        bool operator()(const node &A, const node &B) {
            if (A.ch == B.ch) {
                return A.pos < B.pos;
            }
            return A.ch > B.ch;
        }
    };
    string clearStars(string s) {
        const int len = s.size();
        vector<bool> visited(len, false);
        priority_queue<node, vector<node>, Compare> pq;
        for (int i = 0; i < len; i++) {
            if (s[i] == '*') {
                node top = pq.top();
                pq.pop();
                visited[top.pos] = true;
                visited[i] = true;
            } else {
                pq.push(node(s[i], i));
            }
        }
        string ans;
        ans.resize(len);
        int ind = 0;
        for (int i = 0; i < len; i++) {
            if (!visited[i]) {
                ans[ind++] = s[i];
            }
        }
        return ans.substr(0, ind);
    }
};