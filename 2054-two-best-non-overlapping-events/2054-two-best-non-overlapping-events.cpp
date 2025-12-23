class Solution {
public:
    static bool comparator( vector<int> &A,  vector<int> &B) {
        if (A[1] == B[1]) {
            return A[0] <  B[0];
        }
        return A[1] < B[1];
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<pair<int, int>> pq;
        for (auto event : events) {
            pq.push({-event[1], event[2]});
        }
        int n = events.size();
        int j = 0;
        int ans = 0;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            while (!pq.empty() && -pq.top().first < events[i][0]) {
                auto top = pq.top();
                pq.pop();
                mx =  max(mx, top.second);
            }
            ans = max(ans, mx + events[i][2]);
            // cout << events[i][0] << " " << events[i][1] <<  " " << events[i][2] << " " << mx<< " " << ans << endl;
        }
        return ans;
    }
};