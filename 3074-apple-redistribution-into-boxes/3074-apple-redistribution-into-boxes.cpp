class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end());
        reverse(capacity.begin(), capacity.end());
        int sum = 0;
        for (auto &ap : apple) sum += ap;
        int i = 0;
        for (int &cap : capacity) {
            sum -= cap;
            i++;
            if (sum <= 0) return i; 
        }
        return -1;
    }
};