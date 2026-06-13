class Solution {
public:
    int sumOfWeights(string word, vector<int> &weights) {
        int sum = 0;
        for (auto ch : word) {
            sum += weights[ch - 'a'];
        }
        return sum % 26;
    }
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for (auto word : words) {
            int sum = sumOfWeights(word, weights);
            int con = 25 - sum;
            ans += (char) (con + 'a');
        }
        return ans;
    }
};