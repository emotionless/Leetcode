class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        dist[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto &prev = dist[id];
        string now = prev.first + "-" + stationName;
        hash[now].first += (t - prev.second);
        hash[now].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string now = startStation + "-" + endStation;
        return (0.0 + hash[now].first) / (0.0 + hash[now].second);
    }
private:
    unordered_map<int, pair<string, int>> dist;
    unordered_map<string, pair<int, int>> hash;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */