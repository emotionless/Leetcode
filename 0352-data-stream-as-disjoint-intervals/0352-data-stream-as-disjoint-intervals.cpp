class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        intervals.clear();
    }
    
    void addNum(int val) {
        auto it = intervals.lower_bound(val);
        if (it != intervals.end() && it->first == val) return;
        if (it != intervals.begin()) {
            it--;
            if (it->second >= val) {
                return;
            }
            it++;
        }
        
        int st = val, ed = val;
        if (it != intervals.end() && it->first == (ed + 1)) {
            ed = it->second;
        }
        if (it != intervals.begin()) {
            it--;
            if (it->second == (st - 1)) {
                st = it->first;
            } else {
                it++;
            }
        }
        while (it != intervals.end()) {
            auto nxt = it;
            if (it->first >= st && it->second <= ed) {
                it++;
                nxt = it;
                it--;
                intervals.erase(it);
                it = nxt;
            } else {
                break;
            }
        }
        intervals[st] = ed;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for (auto v : intervals) {
            ans.push_back({v.first, v.second});
        }
        return ans;
    }
private:
    map<int, int> intervals;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */