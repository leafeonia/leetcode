class TimeMap {
public:
    typedef pair<int, string> pi;
    unordered_map<string, vector<pi>> mp;
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto& v = mp[key];
        if (v.empty() || timestamp < v[0].first) return "";
        int left = 0, right = v.size() - 1;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (v[mid].first > timestamp) right = mid - 1;
            else left = mid;
        }
        return v[left].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */