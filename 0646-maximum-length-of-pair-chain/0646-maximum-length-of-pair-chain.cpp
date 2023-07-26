class Solution {
public:
    
    struct comp {
        bool operator()(const vector<int> &A, const vector<int> &B) {
            return A[1] < B[1];
        }
    };
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), comp());
        int cnt = 1;
        int j = 0;
        for (int i = 1; i < pairs.size(); i++) {
            if (pairs[i][0] > pairs[j][1]) {
                cnt++;
                j = i;
            }
        }
        return cnt;
    }
};