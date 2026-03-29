class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        return min(s1[0], s1[2]) == min(s2[0], s2[2]) && 
            max(s1[0], s1[2]) == max(s2[0], s2[2]) && 
            min(s1[1], s1[3]) == min(s2[1], s2[3]) &&
            max(s1[1], s1[3]) == max(s2[1], s2[3]); 
    }
};