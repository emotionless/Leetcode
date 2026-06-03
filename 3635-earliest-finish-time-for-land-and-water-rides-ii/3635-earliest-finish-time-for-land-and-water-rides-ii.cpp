class Solution {
public:
    int minFinish(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int finish1 = INT_MAX;
        for (int i = 0; i < landStartTime.size(); i++) {
            finish1 = min(finish1, landStartTime[i]+ landDuration[i]);
        }
        int finish2 = INT_MAX;
        for (int i = 0; i < waterStartTime.size(); i++) {
            finish2 = min(finish2, max(finish1, waterStartTime[i])+ waterDuration[i]);
        }
        return finish2;
    }

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        return min(
            minFinish(landStartTime, landDuration, waterStartTime,  waterDuration),
            minFinish(waterStartTime,  waterDuration, landStartTime, landDuration)
        );
    }
};