class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int sum = 0;
        int ans = 0;
        unordered_map<int, int> counter;
        counter[0] = 1;
        for (auto v : A) {
            v = (v%K + K)%K;
            sum = (sum + v + K) % K;
            int need = ((sum - K) % K + K) % K;
            ans += counter[need];
            counter[sum]++;
        }
        return ans;
    }
};