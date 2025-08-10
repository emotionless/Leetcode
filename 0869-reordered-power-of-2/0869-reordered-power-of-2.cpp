class Solution {
public:
    string smallestString(int num) {
        string number = "";
        vector<int>digits;
        while (num > 0) {
            digits.push_back(num%10);
            num /= 10;
        }
        sort(digits.begin(), digits.end());
        for (auto d : digits) {
            number = number + (char)(d + '0');
        }
        return number;
    }
    bool reorderedPowerOf2(int n) {
        vector<string> container;
        for(int i = 1; i <= 1e9; i = i*2) {
            string number = smallestString(i);
            container.push_back(number);
        }
        string target = smallestString(n);
        for (auto num : container) {
            if (num == target) return true;
        }
        return false;
    }
};