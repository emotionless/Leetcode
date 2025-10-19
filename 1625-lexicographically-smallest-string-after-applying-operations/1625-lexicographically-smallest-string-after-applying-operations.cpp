class Solution {
public:

    void makeVisited(string s) {
        seen.insert(s);
        ans = min(ans, s);
    }

    string rotate(string s, int b) {
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin() + b);
        reverse(s.begin() + b, s.end());
        return s;
    }

    string add(string s, int a) {
        for (int i = 1; i < n; i+=2) {
            s[i] = (char)((s[i] - '0' + a) % 10 + '0');
        }
        return s;
    }

    bool isVisited(string s) {
        return seen.find(s) != seen.end();
    }

    void dfs(string  s) {
        if (isVisited(s)) {
            return;
        }
        makeVisited(s);
        dfs(rotate(s, b));
        dfs(add(s, a));
        
    }

    string findLexSmallestString(string s, int a, int b) {
        this->a = a;
        this->b = b;
        this->ans = s;
        this->n = s.size();
        dfs(s);

        return ans;
    }
private:
    int n;
    int a, b;
    string ans;
    unordered_set<string> seen;
};