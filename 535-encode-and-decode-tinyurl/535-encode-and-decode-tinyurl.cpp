class Solution {
public:
    const int MOD = 1e9 + 7;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        long long sum = 0;
        for (auto &ch : longUrl) {
            sum = (sum * 26 + (ch - 'a')) % MOD;
        }
        string hash = "";
        char ch;
        while (sum > 0) {
            int rem = sum % 62;
            if (rem < 26) ch = (char) (rem + 'a');
            else if (rem < 52) ch = (char) (rem + 'A' - 26);
            else ch = (char) (rem + '0' - 52);
            hash += ch;
            sum /= 62;
        }
        hashMap[hash] = longUrl;
        return hash;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return hashMap[shortUrl];
    }
private:
    unordered_map<string, string> hashMap;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));