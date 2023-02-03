class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        int i, j,k;
        int per = (numRows-1)*2;
        string ret = "";
        
        if(numRows == 1)  return s;
        if(numRows == 0)  return "";
        
        
        for(i = 0; i < numRows; i++)
        {
            for(j = i; j < len; j = j+per )
            {
                ret += s[j];
                if(j+(numRows-i-1)*2 < len && (j+(numRows-i-1)*2) < (j+per) &&  (j+(numRows-i-1)*2) > (j))
                    ret += s[ j+(numRows-i-1)*2 ];
            }
        }
        return ret;
        
    }
};