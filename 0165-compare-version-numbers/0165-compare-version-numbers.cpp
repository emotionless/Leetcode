class Solution {
public:
    
    int getNextNumber(int &ind, string &version) {
        string num = "0";
        while (ind < version.size() && version[ind] != '.') {
            num += version[ind++];
        }
        return stoi(num);
    }
    
    int compareVersion(string version1, string version2) {
        int ind1 = 0, ind2 = 0;
        while (ind1 < version1.size() || ind2 < version2.size()) {
            int num1 = getNextNumber(ind1, version1);
            int num2 = getNextNumber(ind2, version2);
            if (num1 < num2) {
                return -1;
            } else if (num1 > num2) {
                return 1;
            }
            ind1++;
            ind2++;
        }
        return 0;
    }
};