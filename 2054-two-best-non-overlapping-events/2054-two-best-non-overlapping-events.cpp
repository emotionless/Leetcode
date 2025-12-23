class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<pair<int, int>> pq;
        for (auto event : events) {
            pq.push({-event[1], event[2]});
        }
        int n = events.size();
        int ans = 0;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            while (!pq.empty() && -pq.top().first < events[i][0]) {
                auto top = pq.top();
                pq.pop();
                mx =  max(mx, top.second);
            }
            ans = max(ans, mx + events[i][2]);
        }
        return ans;
    }
};