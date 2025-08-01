class Solution {
public:
    long long power[49] = {
    1LL, 2LL, 4LL, 8LL, 16LL, 32LL, 64LL, 128LL, 256LL, 512LL,
    1024LL, 2048LL, 4096LL, 8192LL, 16384LL, 32768LL, 65536LL, 131072LL, 262144LL, 524288LL,
    1048576LL, 2097152LL, 4194304LL, 8388608LL, 16777216LL, 33554432LL, 67108864LL, 134217728LL, 268435456LL, 536870912LL, 1073741824LL, 2147483648LL, 4294967296LL, 8589934592LL, 17179869184LL, 34359738368LL, 68719476736LL, 137438953472LL, 274877906944LL, 549755813888LL, 1099511627776LL, 2199023255552LL, 4398046511104LL, 8796093022208LL, 17592186044416LL, 35184372088832LL, 70368744177664LL, 140737488355328LL
};


    long long getPrePos(long long &cur) {
        long long last = 0;
        for (int i = 0; i < 49; i++) {
            if (power[i] >= cur) {
                break;
            }
            last = power[i];
        }
        return cur - last;
    }

    char kthCharacter(long long k, vector<int>& operations) {
        if  (k == 1ll) return 'a';
        long long p = 0;
        for (int i = 0; i < 49; i++) {
            if (power[i] >= k) {
                p = power[i-1];
                break;
            }
        }
        int steps = 0;
        vector<int> container;
        while (p >= 1) {
            steps++;
            if (k > p) {
                k = getPrePos(k);
                container.push_back(1);
            } else {
                container.push_back(0);
            }
            p /= 2ll;
        }
        reverse(container.begin(), container.end());
        int ch = 0;
        for (int i = 0; i < container.size(); i++) {
            if (container[i] == 0) continue;
            if (operations[i] == 1) {
                ch = (ch + 1) % 26;
            }
        }
        return (char) (ch + 'a');
    }
};