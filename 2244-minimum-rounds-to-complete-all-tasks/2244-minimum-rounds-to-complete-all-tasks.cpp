class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> freq;
        for (auto &task : tasks) {
            freq[task]++;
        }
        int round = 0;
        for (auto element : freq) {
            if (element.second == 1) return -1;
            round += (element.second + 2)/3;
        }
        return round;
    }
};