class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int st = 0, ed = n - 1;
        int counter = 0;
        while (st <= ed) {
            if ((people[ed] + people[st]) <= limit) {
                st++;
            }
            ed--;
            counter++;
        }
        return counter;
    }
};