class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for (auto &ch : s) {
            if (ch == '*') {
                st.pop();
            } else {
                st.push(ch);
            }
        }
        string ret;
        ret.resize(st.size());
        int ind = st.size() - 1;
        while (st.size()) {
            ret[ind--] = st.top();
            st.pop();
        }
        return ret;
    }
};