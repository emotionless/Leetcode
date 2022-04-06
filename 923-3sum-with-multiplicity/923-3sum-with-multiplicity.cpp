class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int threeSumMulti(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum < target) {
                    j++;
                } else if (sum > target) {
                    k--;
                } else {
                    int cnt1 = 0, cnt2 = 0;
                    if (arr[j] == arr[k]) {
                        ans = (ans + ((k - j + 1) * (k - j))/2) % MOD;
                        j = k;
                    } else {
                        int a = arr[j];
                        while (j < n && arr[j] == a) {
                            cnt1++;
                            j++;
                        }
                        int b = arr[k];
                        while (k >= 0 && arr[k] == b) {
                            cnt2++;
                            k--;
                        }
                        ans = (ans + cnt1 * cnt2) % MOD;
                    }
                }
            }
        }
        return ans;
    }
};