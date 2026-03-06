class Solution {
public:
    bool checkOnesSegment(string s) {
        bool ck=false;
        for(auto ch:s){
            if(ch=='0')ck=true;
            if(ck==true && ch=='1')return false;
        }
        return true;
    }
};