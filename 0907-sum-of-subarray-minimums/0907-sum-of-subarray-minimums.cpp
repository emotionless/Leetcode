class Solution {
public:
    const int mod = 1000000007;
    
    int sumSubarrayMins(vector<int>& A) {
        stack<int> container;
        int n = A.size();
        vector<long long> left(n, 0), right(n, 0);
        for(int i = n - 1; i >= 0; i--) {
            int pos = n;
            while(!container.empty()) {
                int top = container.top();
                if(A[top] > A[i]) container.pop();
                else break;
            }
            if(!container.empty()) pos = container.top();
            right[i] = pos - i;
            container.push(i);
        }
        while(!container.empty()) container.pop();
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            int pos = -1;
            while(!container.empty()) {
                int top = container.top();
                if(A[top] >= A[i]) container.pop();
                else break;
            }
            if(!container.empty()) pos = container.top();
            int now = i - pos;
            ans = (ans + (((now * right[i]) % mod) * A[i])% mod) % mod;
            //cout<<ans<<endl;
            container.push(i);
        }
        return ans;
    }
};