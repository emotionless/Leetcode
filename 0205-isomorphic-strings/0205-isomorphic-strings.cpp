class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> match;
        unordered_set<char> seen;
        for (int i = 0; i < s.size(); i++) {
            char next = t[i];
            if (match.find(s[i]) != match.end()) {
                next = match[s[i]];
            }
            else if (seen.find(t[i]) != seen.end()) {
                return false;
            }
            if (next != t[i]) return false;
            match[s[i]] = t[i];
            seen.insert(t[i]);
        }
        return true;
    }
};

/*

Conditions:
1. If 'a1' already has match, it must be 'a2'
2. If 'a2' already has match, it must be 'a1'
3. match 'a1' <-> 'a2'



match = {
e : a,
g : d
}
seen = {a, d}
*/