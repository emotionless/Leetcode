class Solution {
public:
    
    struct node {
        int ind, c;
        node (int _, int __) {
            ind = _;
            c = __;
        }
        bool operator<(const node &a) const {
            return c > a.c;
        }
    };
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<node> pq;
        int n = points.size();
        pq.push(node(0, 0));
        int ans = 0;
        vector<bool> vis(n, false);
        vector<int> cost(n, INT_MAX);
        
        while(!pq.empty()) {
            node top = pq.top();
            pq.pop();
            int y = top.ind;
            int c = top.c;
            if (vis[y]) continue;
            vis[y] = true;
            ans += c;
            
            for(int i = 0; i < n; i++) {
                if (!vis[i]) {
                    int cst = abs(points[i][0] - points[y][0]) + abs(points[i][1] - points[y][1]);
                    if (cst < cost[i]) {
                        cost[i] = cst;
                        pq.push(node(i, cst));
                    }
                }
            }
        }
        return ans;
    }
};