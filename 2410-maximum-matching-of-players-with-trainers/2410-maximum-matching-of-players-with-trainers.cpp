class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int j = 0;
        int counter = 0;
        int n = trainers.size();
        for (auto player : players) {
            while (j < n && player > trainers[j]) {
                j++;
            }
            if (j >= n) break;
            j++;
            counter++;
        }
        return counter;
    }
};