class Solution {
public:
    string maximumBinaryString(string binary) {
        int len = binary.size();
        int pos = -1;
        int cnt = 0;
        
        for (int i = len - 1; i >= 0; i--) {
            if (binary[i] == '0') {
                pos = i;
                cnt++;
            }
        }
        if (cnt <= 1) return binary;
        for (int i = 0; i < len; i++) binary[i] = '1';
        binary[pos + cnt - 1] = '0';
        return binary;
    }
};