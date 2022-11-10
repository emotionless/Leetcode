class Solution {
public:
    string removeDuplicates(string s) {
        string stak;
        for (auto &ch : s) {
            if (stak.size() && stak.back() == ch) {
                stak.pop_back();
            } else {
                stak.push_back(ch);
            }
        }
        return stak;
    }
};