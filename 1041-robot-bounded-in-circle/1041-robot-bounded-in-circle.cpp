class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, ind = 1;
        
        int total = 4;
        while (total--) {
            for (auto ch : instructions) {
                if (ch == 'L') {
                    ind--;
                } else if (ch == 'R') {
                    ind++;
                } else {
                    x += dr[ind];
                    y += dc[ind];
                }
                ind = (ind + 4) % 4;
            }
        }
        return x == 0 && y == 0;
    }
};