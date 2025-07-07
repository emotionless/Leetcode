class Solution {
public:
    const int MAX = 100000;
    // bool operator<(const pair<int, int> &a, const pair<int, int> &b) {
    //     if (a.first == b.first) return a.second < b.second;
    //     return a.first < b.first;
    // }
    
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<pair<int, int>> p_queue;
        int n = events.size();
        sort(events.begin(), events.end());
        int j = 0;
        int counter = 0;
        for(int i = 1; i <= MAX && (j < n || p_queue.size() > 0); i++) {
            if (p_queue.empty() && j < n) i = max(i, events[j][0]);
            while(j < n && events[j][0] <= i) {
                p_queue.push(make_pair(-events[j][1], -j));
                j++;
            }
            pair<int, int> top;
            while(!p_queue.empty() && -p_queue.top().first < i) {
                // cout << i << " " << (-p_queue.top().first) << endl;
                p_queue.pop();
            }
            if (p_queue.empty()) continue;
            top = p_queue.top();
            p_queue.pop();
            counter++;
        }
        
        return counter;
    }
};