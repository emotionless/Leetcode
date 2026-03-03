class Solution {
public:
    char findKthBit(int n, int k) {
        vector<int> strsSize(n + 1);
        strsSize[1] = 1;
        for (int i = 2; i <= n; i++) {
            strsSize[i] = strsSize[i-1] * 2 + 1;
        }
        int times = 0;
        while (n > 1) {
            if (k == (strsSize[n]/2 + 1)) {
                if (times%2) return '0';
                return '1';
            } else if (k > strsSize[n]/2) {
                k = strsSize[n] - k + 1;
                times++;
            }
            n--;
        }
        if (times%2) return '1';
        return '0';
    }
};