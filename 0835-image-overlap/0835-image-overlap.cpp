class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<int> arr1;
        vector<int> arr2;
        int N = img1.size();
        for (int i = 0; i < N*N; i++) {
            if (img1[i/N][i%N]) {
                arr1.push_back(i/N * 100 + i%N);
            }
        }
        for (int i = 0; i < N*N; i++) {
            if (img2[i/N][i%N]) {
                arr2.push_back(i/N * 100 + i%N);
            }
        }
        unordered_map<int, int> counter;
        int ans = 0;
        for (auto &i : arr1) {
            for (auto &j : arr2) {
                counter[i - j]++;
                ans = max(ans, counter[i - j]);
            }
        }
        return ans;
    }
};