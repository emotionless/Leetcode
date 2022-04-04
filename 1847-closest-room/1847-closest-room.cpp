class Solution {
public:
    
    struct comparator {
        bool operator()(const vector<int> &a, const vector<int> &b) {
            if (a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        }
    };
    
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int sz = queries.size();
        int ind = 0;
        for (auto &v : queries) {
            v.push_back(ind++);
            v[0] *= -1;
            rooms.push_back(v);
        }
        sort(rooms.begin(), rooms.end(), comparator());
        
        int n = rooms.size();
        vector<int> ans(sz, -1);
        set<int> container;
        for (int i = n - 1; i >= 0; i--) {
            if (rooms[i].size() == 3) { // query
                int id = rooms[i][2];
                int mn = INT_MAX;
                int val = -1;
                auto it = container.upper_bound(-rooms[i][0]);
                if (it != container.end()) {
                    if (abs(*it + rooms[i][0]) <= mn) {
                        val = *it;
                        mn = *it + rooms[i][0];
                    }
                }
                if (it != container.begin()) {
                    it--;
                    if (abs(*it + rooms[i][0]) <= mn) {
                        val = *it;
                        mn = abs(*it + rooms[i][0]);
                    }
                }
                ans[id] = val;
            } else {
                container.insert(rooms[i][0]);
            }
        }
        return ans;
    }
};