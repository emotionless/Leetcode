class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        if (!n) return true;
        unordered_map<char, int> counter;
        for (auto &word : words) {
            for (auto &ch : word) {
                counter[ch]++;
            }
        }
        for (auto ele : counter) {
            if (ele.second % n) return false;
        }
        return true;
    }
};