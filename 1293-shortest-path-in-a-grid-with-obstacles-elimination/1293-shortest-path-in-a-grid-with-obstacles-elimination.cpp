class Solution {
public:
    int directionR[4] = {-1, 0, 1, 0};
    int directionC[4] = {0, 1, 0, -1};
    
    struct node {
        int x, y, steps, cost;
        node(int a, int b, int c, int d) {
            x = a;
            y = b;
            steps = c;
            cost = d;
        }
    };
    
    int breadthFirstSearch(const vector<vector<int>> &grid, const int &k) {
        int numOfRows = grid.size();
        int numOfCols = grid[0].size();
        queue<node> container;
        container.push(node(0, 0, 0, 0));
        vector<vector<vector<int>>> vis(numOfRows, vector<vector<int>>(numOfCols, vector<int>(k+2, false)));
        
        while (!container.empty()) {
            auto current = container.front();
            container.pop();
            int x = current.x;
            int y = current.y;
            int cost = current.cost;
            int steps = current.steps;
            //cout << x << " " << y << " " << steps << endl;
            if (steps > k) continue;
            if (vis[x][y][steps] == true) continue;
            if (x == (numOfRows - 1) && y == (numOfCols - 1)) return cost;
            vis[x][y][steps] = true;
            for (int ind = 0; ind < 4; ind++) {
                int adjx = x + directionR[ind];
                int adjy = y + directionC[ind];
                if (adjx < 0 || adjx >= numOfRows || adjy < 0 || adjy >= numOfCols) continue;
                int nextSteps = steps + grid[adjx][adjy];
                if (vis[adjx][adjy][nextSteps]) continue;
                //cout << adjx << " " << adjy << " cost: " << nextSteps << " " << cost << endl;
                container.push(node(adjx, adjy, nextSteps, cost + 1));
            }
        }
        return -1;
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        return breadthFirstSearch(grid, k);
    }
};