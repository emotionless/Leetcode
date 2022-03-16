class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0;
        int ind = 0;
        int sz = popped.size();
        for (auto num : pushed) {
            pushed[i++] = num;
            while (i && ind < sz && pushed[i-1] == popped[ind]) {
                ind++;
                i--;
            }
        }
        return ind == sz;
    }
};