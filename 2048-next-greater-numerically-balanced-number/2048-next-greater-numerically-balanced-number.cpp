class Solution {
public:
    bool isBalanced(int num) {
        counter.clear();
        counter.resize(10, 0);
        while (num) {
            int d = num % 10;
            num /=  10;
            counter[d]++;
        }
        for (int i = 0; i < 10; i++) {
            if (counter[i] > 0) {
                if (counter[i] != i) return false;
            }
        }
        return  true;
    }
    int nextBeautifulNumber(int n) {
        int num = n;
        num++;
        while (true) {
            if (isBalanced(num)) return num;
            num++;
        }
        return 0;
    }
private:
    vector<int> counter;
};