class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        vector<int> answer;
        int start = 0, end = 0;
        for (auto num : arr) {
            end = answer.size();
            answer.push_back(num);
            for (int i = start; i < end; i++)  {
                if (answer.back() < (answer[i] | num)) {
                    answer.push_back(answer[i] | num);
                }
            }
            start = end;
        }
        return unordered_set(answer.begin(), answer.end()).size();
    }
};