const int MAXX = 1e6 + 7;
unordered_map<int,  vector<int>> prime;

bool initialized = []() {
    for (int i = 2; i < MAXX; i++) {
        if (prime[i].size())  continue;
        for (int j = i; j < MAXX;  j += i) {
            // is[j] = true;
            prime[j].push_back(i);
        }
    }
    return true;
}();

class Solution {
public:
    
    int minJumps(vector<int>& nums) {
        // cout <<"started" << endl;
        // is.resize(MAXX, false);
        // sieve();
        unordered_map<int, vector<int>> edge;
        int n = nums.size();
        for (int  i = 0; i < n; i++) {
            for (auto p : prime[nums[i]]) {
                edge[p].push_back(i);
            }
        }

        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        vector<bool> seen(n, false);
        // seen[0] = true;
        // cout << "here" <<  endl;

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            int ind = cur.first;
            int num = nums[cur.first];
            int cost = cur.second;
            // cout << ind << endl;
            if (seen[ind]) continue;
            seen[ind] = true;
            if (ind == (n-1)) return cost;
            
            q.push({ind + 1, cost + 1});
            if (ind > 0)
                q.push({ind - 1, cost + 1});
            for (auto i : edge[num]) {
                q.push({i, cost + 1});
            }
            edge[num].clear();
        }
        return -1;
    }
};