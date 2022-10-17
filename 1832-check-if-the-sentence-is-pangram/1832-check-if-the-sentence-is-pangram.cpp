class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> container;
        for (auto &ch : sentence) {
            container.insert(ch);
        }
        return container.size() == 26;
    }
};