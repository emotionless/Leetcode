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

/*
Since you nailed the optimal logic, can you think of how to handle this if the input stream was infinite and you couldn't store all colors?

Solution:
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main()
{
    std::string name;
      
    int pos = 0;
    int ans = 0;
    int f1 = -1, f1v = -1, s1v = -1, s1 = -1;
    int f2 = -1, f2v = -1, s2v = -1, s2 = -1;
    int color;
    while (cin >> color) {
        if (f1 == -1) {
            f1 = pos;
            f1v = color;
        } else if (s1 == -1 && color != f1v) {
            s1 = pos;
            s1v = color;
            s2 =  pos;
            s2v = color;
            ans = max(ans, pos);
        } else if (f2v == color) {
            s2 = f2;
            s2v = f2v;
        }
    
        f2 = pos;
        f2v = color;
    
        if (f1v != f2v) {
            ans = pos;
        } else {
            ans = max(ans, max(f2 - s1, s2 - f1));
        }
        cout << ans << endl;
        pos++;
    }
    
    return 0;
}
1 2 1 1 1 1 1 1 3 1
1, 2, 1, 1, 1, 3, 1, 1, 1, 2, 1
*/