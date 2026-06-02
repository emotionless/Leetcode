class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((landStartTime[i] + landDuration[i]) >= waterStartTime[j]) {
                    ans = min(ans,  landStartTime[i] + landDuration[i] + waterDuration[j]);
                } else {
                    ans = min(ans, waterStartTime[j] + waterDuration[j] );
                }
                if ((waterStartTime[j] + waterDuration[j]) >= landStartTime[i]) {
                    ans = min(ans,  waterStartTime[j] + waterDuration[j] + landDuration[i]);
                } else {
                    ans = min(ans, landStartTime[i] + landDuration[i] );
                }
                
            }
        }
        return ans;
    }
};