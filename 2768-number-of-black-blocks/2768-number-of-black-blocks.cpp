class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        map<pair<int, int>, int> counter;
        for (auto &coordinate : coordinates) {
            for (int i = -1; i < 1; i++) {
                for (int j = -1; j < 1; j++) {
                    int ax = coordinate[0] + i;
                    int ay = coordinate[1] + j;
                    if (ax < 0 || ay < 0 || ax >= (m - 1) || ay >= (n-1)) continue;
                    counter[make_pair(ax, ay)]++;
                }
            }
        }
        long long total = (n - 1ll) * (m - 1ll);
        vector<long long> arr(5, 0ll);
        for (auto mp : counter) {
            total -= 1;
            arr[mp.second]++;
        }
        arr[0] = total;
        return arr;
    }
};