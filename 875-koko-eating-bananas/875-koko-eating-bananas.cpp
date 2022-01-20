class Solution {
public:
    
    int coveredBy(vector<int> &piles, int tar) {
        int ret = 0;
        for (auto pile : piles) {
            ret += pile/tar + (pile%tar?1:0);
        }
        return ret;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int st = 1, ed = 0;
        for (auto pile : piles) {
            ed = max(ed, pile);
        }
        int ans = ed;
        while (st <= ed) {
            int mid = (st + ed) / 2;;
            int need = coveredBy(piles, mid);
            if (need <= h) {
                ans = mid;
                ed = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
};