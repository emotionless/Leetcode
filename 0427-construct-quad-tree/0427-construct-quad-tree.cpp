/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    
    int getSum(int x1, int y1, int x2, int y2, const vector<vector<int>> &grid) {
        return grid[x2][y2] - (y1>0?grid[x2][y1-1]:0) - (x1>0? grid[x1-1][y2]:0) + (x1 > 0 && y1 > 0? grid[x1-1][y1-1] : 0);
    }
    
    Node* solve(int x1, int y1, int x2, int y2, int lvl, const vector<vector<int>> &grid) {
        if (x1 > x2 || y1 > y2) return new Node();
        
        int sum = getSum(x1, y1, x2, y2, grid);
        if (sum == (x2-x1 + 1)*(y2 - y1 + 1) || sum == 0) {
            
            return new Node(sum, true);
        } else {
            Node *cur = new Node(sum, false);
            int xMid = (x1 + x2) / 2;
            int yMid = (y1 + y2) / 2;
            cur -> topLeft = solve(x1, y1, xMid, yMid, lvl + 1, grid);
            cur -> topRight = solve(x1, yMid + 1, xMid, y2, lvl + 1, grid);
            cur -> bottomLeft = solve(xMid + 1, y1, x2, yMid, lvl + 1, grid);
            cur -> bottomRight = solve(xMid + 1, yMid + 1, x2, y2, lvl + 1, grid);
            
            return cur;
        }
    }
    
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] += (i>0? grid[i-1][j] : 0) + (j > 0? grid[i][j-1] : 0) - (i>0 && j>0? grid[i-1][j-1] : 0);
            }
        }
        return solve(0, 0, n-1, n-1, 0, grid);
    }
private:
    unordered_map<int, vector<Node*>> save;
};