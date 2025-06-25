class Solution {
public:

    int binary_search_num2(int num, long long target, const vector<int> &nums2) {
        int st = 0, ed = nums2.size() - 1;
        int ans = -1;
        while (st <= ed) {
            int mid = (st + ed) / 2;
            if ((long long) nums2[mid] * num <= target) {
                ans = mid;
                st = mid + 1;
            } else {
                ed = mid - 1;
            }
        }
        return ans + 1;
    }

    long long getLessNumber(long long mid, const vector<int> &nums1,  const vector<int> nums2, const vector<int> &positive, vector<int> &negative) {
        long long ans = 0;
        for (auto num : nums1) {
            if (num >= 0) {
                ans += binary_search_num2(num, mid, nums2);
            } else {
                ans += binary_search_num2(num, mid, positive);
                ans += binary_search_num2(num, mid, negative);
            }
        }
        return ans;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        vector<int> positive, negative;
        for (auto num : nums2) {
            if (num < 0) {
                negative.push_back(num);
            } else {
                positive.push_back(num);
            }
        }
        reverse(positive.begin(), positive.end());
        reverse(negative.begin(), negative.end());
        long long st = -1e12, ed = 1e12;
        long long ans = -1;
        while (st <= ed) {
            long long mid = (st + ed) / 2;
            long long lessNumberCount = getLessNumber(mid, nums1, nums2, positive, negative);
            // cout << mid << " " << lessNumberCount << endl;
            if (lessNumberCount >= k) {
                ans = mid;
                ed = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
};