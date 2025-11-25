class Solution {
public:
    bool is_prime(long long num) {
        if (num == 2) return true;
        if (num%2 == 0 || num == 1) return false;
        int sq = sqrt(num);
        for (int i = 3;  i <= sq; i += 2) {
            if (num%i == 0) return false;
        }
        return true;
    }
    long long sumOfLargestPrimes(string s) {
        int len = s.length();
        vector<long long> candidates;
        for (int i = 0; i < len;  i++) {
            string str = "";
            for (int j = i; j < len ; j++) {
                str += s[j];
                long long num = stoll(str);
                if (is_prime(num)) {
                    // cout << num << endl;
                    candidates.push_back(num);
                }
            }
        }
        sort(candidates.begin(), candidates.end());
        candidates.erase( unique( candidates.begin(), candidates.end() ), candidates.end() );
        reverse(candidates.begin(), candidates.end());
        
        int sz = candidates.size();
        long long sum = 0;
        for (int i = 0; i < 3 && i < sz; i++) sum += candidates[i];
        return sum;
    }
};