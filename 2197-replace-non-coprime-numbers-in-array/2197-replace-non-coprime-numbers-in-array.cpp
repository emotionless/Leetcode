#include <algorithm>

class Solution {
public:
    long long gcd(long long a , long long b)
    {
        if(b==0) return a;
        a%=b;
        return gcd(b,a);
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> container;
        for (int num : nums) {
            bool ck = false;
            container.push(num);
            while (container.size() > 1) {
                ck = true;
                long long top1 = container.top();
                container.pop();
                long long top2 = container.top();
                container.pop();
                if (gcd(top1, top2) > 1) {                
                    long long lcm = (top1*top2) / gcd(top2, top1);
                    container.push(lcm);
                } else {
                    container.push(top2);
                    container.push(top1);
                    break;
                }
            }
        }
        int sz = container.size();
        cout << sz << endl;
        vector<int> res(sz, 0);
        while (container.size()) {
            res[--sz] = container.top();
            container.pop();
        }
        return res;
    }
};