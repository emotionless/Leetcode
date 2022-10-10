class Solution {
public:
    
    int getTimesAppear(const string &str, const char tar) {
        int cnt = 0;
        for (auto &ch : str) {
            if (ch == tar) cnt++;
        }
        return cnt;
    }
    
    int getCost(char ch, vector<string> &garbage, vector<int> &travel) {
        int n = garbage.size();
        int sum = 0;
        int pre = 0;
        for (int i = 0; i < n; i++) {
            int times = getTimesAppear(garbage[i], ch);
            sum += times;
            if (times) {
                pre = 0;
            }
            if (i < (n-1)) {
                pre += travel[i];
                sum += travel[i];
            }
        }
        
        return sum - pre;
    }
    
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        return getCost('G', garbage, travel) + getCost('P', garbage, travel) + getCost('M', garbage, travel); 
    }
};