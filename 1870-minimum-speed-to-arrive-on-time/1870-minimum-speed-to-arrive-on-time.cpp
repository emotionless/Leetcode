class Solution {
public:
    
    double needTime(vector<int> &dist, int speed) {
        int n = dist.size();
        double total = 0.0;
        for (int i = 0; i < (n-1); i++) {
            int need = dist[i]/speed + (dist[i]%speed? 1 : 0);
            total += need;
        }
        total += (double)dist[n-1]/(0.0 + speed);
        return total;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int st = 1, ed = 10000000, ans = -1;
        while (st <= ed) {
            int mid = (st + ed) / 2;
            double need = needTime(dist, mid);
            if (need <= hour) {
                ans = mid;
                ed = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
};