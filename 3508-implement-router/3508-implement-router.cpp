class Router {
public:

    Router(int memoryLimit) {
        limit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        vector<int> cur = {source, destination, timestamp};
        if (seen.count(cur) > 0) return false;
        container.push({source, destination, timestamp});
        if (container.size() > limit) {
            forwardPacket();
        }
        destTime[destination].push_back(timestamp);

        seen[cur]++;
        return true;
    }
    
    vector<int> forwardPacket() {
        if (container.size() > 0) {
            auto top = container.front();
            container.pop();
            seen.erase(top);
            st[top[1]]++;
            return top;
        }
        return {};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto &cur = destTime[destination];
        auto begin = lower_bound(cur.begin() + st[destination], cur.end(), startTime);
        auto end = upper_bound(cur.begin() + st[destination], cur.end(), endTime);

        return end - begin;
    }
private:
    int limit = 0;
    queue<vector<int>> container;
    unordered_map<int, vector<int>> destTime;
    map<vector<int>, int> seen;
    unordered_map<int, int> st;
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */