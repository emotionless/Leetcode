class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int len = s.length();
        int p = 1;
        for (int i = 1; i <= k; i++) {
            p = p * 2;
        }
        unordered_set<int> container;
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum = sum << 1;
            sum += (s[i] - '0');
            if ((i+1) >= k) {
                int j = i - k;
                if (j >= 0) {
                    sum -= p * (s[j] - '0');
                }
                container.insert(sum);
                if (container.size() == p) return true;
            }
            //cout << i << " " << sum << endl;
        }
        return container.size() == p;
    }
};