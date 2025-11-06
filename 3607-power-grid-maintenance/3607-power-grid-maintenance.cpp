class Solution {
public:
    int getParent(int u) {
        if (parent[u] == u) return u;
        return parent[u] = getParent(parent[u]);
    }
    void deep_copy_elements(priority_queue<int, vector<int>, greater<int>> &pq1, priority_queue<int, vector<int>, greater<int>> &pq2) {
        while (!pq2.empty()) {
            auto top = pq2.top();
            pq2.pop();
            pq1.push(top);
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        parent.resize(c + 1, -1);
        visited.resize(c + 1, false);
        for (int i = 0; i <= c; i++) parent[i] = i;
        for (auto con : connections) {
            int u = con[0];
            int v = con[1];
            int pu = getParent(u);
            int pv = getParent(v);
            if (pu != pv) {
                if (pu > pv) {
                    parent[pu] = pv;
                    deep_copy_elements(container[pv], container[pu]);
                    container[pv].push(u);
                    container[pv].push(v);
                }
                else {
                    parent[pv] = pu;
                    deep_copy_elements(container[pu], container[pv]);
                    container[pu].push(u);
                    container[pu].push(v);
                }
            }
            // pv = getParent(pv);
            // cout << u << " " << v << " " << pv << endl;
            // container[pv].push(u);
            // container[pv].push(v);
        }
        vector<int> ans;
        for (auto &query : queries) {
            int u = query[0];
            int v = query[1];
            int found = -1;
            if (u == 2) {
                visited[v] = true;
            } else if (!visited[v]) {
                ans.push_back(v);
            } else {  
                int root = getParent(v);
                auto &cur = container[root];
                while (!cur.empty()) {
                    auto top = cur.top();
                    cur.pop();
                    if (!visited[top]) {
                        found = top;
                        break;
                    }
                }
                ans.push_back(found);
            }
        }
        return ans;
    }
private:
    vector<int> parent;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> container;
    vector<bool> visited;
};