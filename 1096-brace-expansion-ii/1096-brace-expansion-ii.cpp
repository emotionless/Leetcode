// solution understood from https://leetcode.com/problems/brace-expansion-ii/discuss/317890/Simple-solution-(C%2B%2B)

class Solution {
public:
    
    string getWord(const string &s, int &ind) {
        string ret = "";
        while (ind < s.length() && s[ind] >= 'a' && s[ind] <= 'z') {
            ret += s[ind++];
        }
        return ret;
    }
    
    unordered_set<string> dfs(const string &s, int &ind) {
        unordered_set<string> res;
        unordered_set<string> container;
        while (ind < s.length() && s[ind] != '}') {
            if (s[ind] == ',') {    // concatenation
                for (auto it : container) {
                    res.insert(it);
                }
                container.clear();
                ind++;
            }
            unordered_set<string> tmp;
            if (s[ind] == '{') {
                ind++;
                tmp = dfs(s, ind);
                ind++;
            } else {
                tmp.insert(getWord(s, ind));
            }
            if (container.size() == 0) {
                container = tmp;
            } else {
                // cartesian product
                unordered_set<string> tmp2;
                for (auto it1 : container) {
                    for (auto it2 : tmp) {
                        tmp2.insert(it1 + it2);
                    }
                }
                swap(container, tmp2);
            }
        }
        for (auto it : container) {
            res.insert(it);
        }
        return res;
    }
    
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        auto strs = dfs(expression, i);
        vector<string> res;
        for (auto v : strs) {
            res.push_back(v);
        }
        sort(res.begin(), res.end());
        return res;
    }
};