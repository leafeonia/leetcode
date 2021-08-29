class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        idMap[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string name = idMap[id].first + "," + stationName;
        int timeCost = t - idMap[id].second;
        idMap.erase(id);
        if (timeMap.find(name) == timeMap.end()) {
            timeMap[name] = {1, (double)timeCost};
        } else {
            timeMap[name].second = (timeMap[name].second * timeMap[name].first + timeCost) / (timeMap[name].first + 1);
            timeMap[name].first++;
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        return timeMap[startStation + "," + endStation].second;
    }
    
    unordered_map<int, pair<string, int>> idMap;
    unordered_map<string, pair<int, double>> timeMap;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */