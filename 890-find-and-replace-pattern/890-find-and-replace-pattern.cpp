class Solution {
public:
    
    string convert(string text) {
        unordered_map<char, int> mapped;
        for (int i = 0; i < text.size(); i++) {
            if (mapped.find(text[i]) == mapped.end()) {
                mapped[text[i]] = i;
            }
        }
        for (auto &ch : text) {
            ch = ('a' + mapped[ch]);
        }
        return text;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n = words.size();
        vector<string> ans;
        string pat = convert(pattern);
        for (auto str : words) {
            if (convert(str) == pat) {
                ans.push_back(str);
            }
        }
        return ans;
    }
};