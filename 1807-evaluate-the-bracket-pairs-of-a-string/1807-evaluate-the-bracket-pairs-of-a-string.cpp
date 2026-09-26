class Solution {
public:
    string evaluate(const string &s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> hashed;
        for (auto ele : knowledge) {
            hashed[ele[0]] = ele[1];
        }
        int len = s.length();
        string ret = "";
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') {
                int j = i + 1;
                string str = "";
                while (j < len && s[j] != ')') {
                    str += s[j];
                    j++;
                }
                if (hashed.find(str) != hashed.end()) {
                    ret += hashed[str];
                } else {
                    ret += "?";
                }
                i = j;
            } else {
                ret += s[i];
            }
        }
        return ret;
    }
};