class Solution {
public:
    
    int numberOfBalls(int dif, vector<int> &positions) {
        int cur = positions[0] + dif;
        int cnt = 1;
        int ind = 0;
        int n = positions.size();
        while (ind < n) {
            while (ind < n && positions[ind] < cur) {
                ind++;
            }
            if (ind < n) {
                cnt++;
                cur = positions[ind] + dif;
            }
        }
        return cnt;
    }
    
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int st = 1, ed = position[n-1], ans = -1;
        while (st <= ed) {
            int mid = (st + ed) / 2;
            if (numberOfBalls(mid, position) >= m) {
                ans = mid;
                st = mid + 1;
            } else {
                ed = mid - 1;
            }
        }
        return ans;
    }
};