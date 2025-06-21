class Solution {
public:
    int minimumDeletions(string word, int K) {
        int len = word.size();
        unordered_map<char, int> count;
        for (int i = 0; i < len; i++) {
            count[word[i]]++;
        }
        vector<int> nums;
        int sum = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i+'a'] > 0) {
                nums.push_back(count[i+'a']);
                sum += count[i+'a'];
            }
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = len;
        for (int i = 0; i < n; i++) {
            int j = 0;
            int total = 0;
            // cout << nums[i] << endl;
            for (j = i; j < n; j++) {
                if ((nums[j] - nums[i]) > K) {
                    break;
                }
            }
            for (int k = j; k < n; k++) {
                total += nums[k] - (nums[i] + K);
            }
            for (int k = 0; k < i; k++) {
                total += nums[k];
            }

            // cout << nums[i] << " " << j << " " << total << endl;
            ans = min(ans, total);
        }
        return ans;
    }
};