class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto it = lower_bound(letters.begin(), letters.end(), target + 1);
        if (it  == letters.end()) return *letters.begin();
        return *it;
    }
};