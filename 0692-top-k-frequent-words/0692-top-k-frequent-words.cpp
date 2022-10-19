#include <set>

class Solution {
public:
    
    struct node {
        int first;
        string second;
        
        node(){}
        node(int f, string s) {
            first = f;
            second = s;
        }
        bool operator<(const node &cur) const {
            if (first == cur.first) return second > cur.second;
            return first < cur.first;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> counter;
        for(auto x : words) {
            counter[x]++;
        }
        set<node> container;
        for(auto x : counter) {
            container.insert(node(x.second, x.first));
            if (container.size() > k) container.erase(container.begin());
        }
        vector<string> ans;
        for(auto it = container.rbegin(); it != container.rend(); it++) {
            ans.push_back(it->second);
        }
        return ans;
    }
};