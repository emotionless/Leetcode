class Robot {
public:
    Robot(int width, int height) {
        h =  height;
        w = width;
        x = y = 0;
        dir  = 0;
    }
    
    void step(int num) {
        while (num > 0) {
            int adjx = x + dirx[dir];
            int adjy = y + diry[dir];
            if (adjx < 0 || adjx >= w || adjy < 0 || adjy >= h) {
                
                num %= 2*(h + w - 2);
                if (num == 0) {
                    return;
                }
                dir++;
                dir = dir % 4;
                continue;
            }
            num--;
            x = adjx;
            y = adjy;
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        switch(dir) {
            case 0:
                return "East";
            case 1:
                return "North";
            case  2:
                return "West";
            default:
                return "South";
        }
    }
private:
    int h, w;
    int x, y;
    int dirx[4] = {1, 0,  -1, 0};
    int diry[4] = {0,  1,  0, -1};
    int dir = 0;
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */