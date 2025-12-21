class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        if (n == 0) return 0;
        int len = strs[0].size();
        vector<bool> isSorted(len, false);
        int ans = 0;
        for (int j = 0; j < len; j++) {
            bool possible = true;
            for (int i = 1; i < n; i++) {
                if (isSorted[i] == false && strs[i][j] < strs[i-1][j]) {
                    possible = false;
                    break;
                }
            }
            if (possible == true) {
                for (int i = 1; i < n; i++) {
                    isSorted[i] = isSorted[i] || strs[i][j] > strs[i-1][j];
                }
            } else {
                ans++;
            }
        }
        return ans;
    }
};

/*

["vdy"
,"vei"
,"zvc"
,"zld"
]

*/