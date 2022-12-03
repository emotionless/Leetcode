class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> frequency;
        for (auto ch : s) {
            frequency[ch]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto element : frequency) {
            pq.push({element.second, element.first});
        }
        string answer = "";
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int times = top.first;
            char curChar = top.second;
            while (times--) {
                answer += curChar;
            }
        }
        return answer;
    }
};