class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        if  (colors[0] != colors[n-1])  return n - 1;
        int f = 0, s  = n-1;
        while  (f <  n && colors[f] == colors[0])  f++;
        while  (s >= 0 && colors[s] == colors[n-1])  s--;
        return max(n-f-1, s);
    }
};