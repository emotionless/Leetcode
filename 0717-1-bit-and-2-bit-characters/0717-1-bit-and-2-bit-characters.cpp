class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i, len = bits.size();
        for (i = 0;i < len-1; i++) {
            if (bits[i] == 0) continue;
            else i++;
        }
        return i == (len - 1);
    }
};