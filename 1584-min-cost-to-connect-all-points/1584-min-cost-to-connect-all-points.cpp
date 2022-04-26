class Solution {
public:
    
    struct node {
        int x, y, c;
        node (int _, int __, int ___) {
            x = _;
            y = __;
            c = ___;
        }
        bool operator<(const node &a) const {
            return c > a.c;
        }
    };
    
    // vector<int> par;
    
    // int find(int x) {
    //     if (par[x] == x) return x;
    //     return par[x] = find(par[x]);
    // }
    
    int cost[1001];
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<node> pq;
        int n = points.size();
        // par.resize(n);
        
        // for(int i = 0; i < n; i++) {
        //     par[i] = i;
        //     for(int j = i + 1; j < n; j++) {
        //         pq.push(node(i, j, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])));
        //     }
        // }
        pq.push(node(0, 0, 0));
        int ans = 0;
        bool vis[n];
        memset(vis, false, sizeof vis);
        for(int i = 0; i < n; i++) {
            cost[i] = INT_MAX;
        }
        while(!pq.empty()) {
            node top = pq.top();
            pq.pop();
            int x = top.x;
            int y = top.y;
            int c = top.c;
            
            // int px = find(x);
            // int py = find(y);
            if (vis[y]) continue;
            vis[y] = true;
            // par[px] = py;
            ans += c;
            
            for(int i = 0; i < n; i++) {
                if (!vis[i]) {
                    int cst = abs(points[i][0] - points[y][0]) + abs(points[i][1] - points[y][1]);
                    if (cst < cost[i]) {
                        cost[i] = cst;
                        pq.push(node(y, i, cst));
                    }
                }
            }
        }
        return ans;
    }
};