class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k%2 == 0 || k%5 == 0) return -1;
        int num = 1;
        int len = 1;
        unordered_set<int> visited;
        while (num) {
            num %= k;
            if (num == 0) return len;
            if (visited.find(num) != visited.end()) {
                return -1;
            }
            visited.insert(num);
            num = num*10 + 1;
            len++;
        }
        return -1;
    }
};