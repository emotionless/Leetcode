

class Solution {
public:
    bool leftAvailable(int r) {
        return  r&30;
    }
    
    bool rightAvailable(int r) {
        return r&480;
    }
    
    bool middleAvailable(int r) {
        return r&120;
    }
    
    
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // book.clear();
        
        unordered_map<int, int > book;
        for(vector<int> seat : reservedSeats) {
            int r = seat[0] - 1, c = seat[1] - 1;
            
            book[r] |= (1<<(c));
        }
        bool l, rr,m;
        int ans = n * 2, r;
        for(auto cur : book) {
            r = cur.second;
            l = leftAvailable(r), rr = rightAvailable(r), m = middleAvailable(r);
            if(l && rr && m) ans -= 2;
            else
                ans -= (l | rr | m);
        }
        return ans;
    }
};