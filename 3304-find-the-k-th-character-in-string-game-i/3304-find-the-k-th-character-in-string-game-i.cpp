class Solution {
public:
    int power[30] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912};

    int getPrePos(int cur) {
        int last = 0;
        for (int i = 0; i < 30; i++) {
            if (power[i] > cur) {
                break;
            }
            last = power[i];
        }
        return cur - last;
    }

    char kthCharacter(int k) {
        int steps = 0;
        while (k > 1) {
            steps++;
            k = getPrePos(k);
        }
        return (char)('a' + steps%26);
    }
};