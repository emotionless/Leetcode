class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        unordered_set<long long> seenh, seenv;
        hFences.insert(hFences.begin(), 1);
        hFences.push_back(m);
        vFences.insert(vFences.begin(), 1);
        vFences.push_back(n);
        
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        int sz = hFences.size();
        int vSz = vFences.size();
        long long ans = 0;
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                long long diff = hFences[j] - hFences[i];
                seenh.insert(diff);
            }
        }
        for (int i = 0; i < vSz; i++) {
            for (int j = i + 1; j < vSz; j++) {
                long long diff = vFences[j] - vFences[i];
                if (seenh.find(diff) != seenh.end()) {
                    ans = max(ans, diff);
                }
            }
        }

        return ans == 0? -1 : (ans * ans) % 1000000007;
    }
};