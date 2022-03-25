class Solution {
public:
    int numRabbits(vector<int>& answers) {
        sort(answers.begin(), answers.end());
        int total = 0;
        int n = answers.size();
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            int times = answers[i];
            total += answers[i] + 1;
            while (times > 0 && j < n && answers[j] == answers[i]) {
                times--;
                j++;
            }
            i = j - 1;
        }
        return total;
    }
};